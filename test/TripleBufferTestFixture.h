/*
 * TripleBufferTestFixture.h
 *
 *  Created on: Aug 20, 2019
 *      Author: thepursuer
 */

#ifndef TEST_TRIPLEBUFFERTESTFIXTURE_H_
#define TEST_TRIPLEBUFFERTESTFIXTURE_H_

#include <gtest/gtest.h>

#include "TripleBuffer.h"

class TripleBufferTestFixture : public testing::Test {
public:
	virtual void SetUp(){}
	virtual void TearDown(){}

	TripleBuffer<int> buf;
};

#endif /* TEST_TRIPLEBUFFERTESTFIXTURE_H_ */
