/*
 * TripleBuffer.h
 *
 *  Created on: Aug 20, 2019
 *      Author: thepursuer
 */

#ifndef TRIPLEBUFFER_H_
#define TRIPLEBUFFER_H_
#include <atomic>
#include <memory>

/*
 * TripleBuffer implementation
 */
template <typename T>
class TripleBuffer{
private:
	std::atomic<T*> firstBuf_;
	std::atomic<T*> secondBuf_;
	std::atomic<T*> thirdBuf_;

	const T* PermanentAdresses_ [3];

	std::atomic<bool> stale_;

public:
	TripleBuffer();
	~TripleBuffer();

	void update(T val);
	T read();
	bool isStale() const;

	//NO COPIES
	TripleBuffer(TripleBuffer& other) = delete;
	TripleBuffer(TripleBuffer&& other) = delete;
	TripleBuffer& operator=(TripleBuffer& other) = delete;
};

template<typename T>
TripleBuffer<T>::TripleBuffer():
firstBuf_(new T()),
secondBuf_(new T()),
thirdBuf_(new T()),
PermanentAdresses_{firstBuf_, secondBuf_, thirdBuf_}
{
	stale_ = true;
}

template<typename T>
TripleBuffer<T>::~TripleBuffer() {
	for(int i = 0; i < 3; i++)
		delete PermanentAdresses_[i];
}

template<typename T>
void TripleBuffer<T>::update(T val) {
	*firstBuf_ = val;//Copy the value
	firstBuf_ = secondBuf_.exchange(firstBuf_);//Swap the pointers
	stale_ = false;
}

template<typename T>
T TripleBuffer<T>::read() {
	thirdBuf_ = secondBuf_.exchange(thirdBuf_);//Swap the pointers
	stale_ = true;
	return *thirdBuf_;//Return the value
}

template<typename T>
bool TripleBuffer<T>::isStale() const {
	return stale_;
}

#endif /* TRIPLEBUFFER_H_ */
