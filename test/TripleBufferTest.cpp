/*
 * TripleBufferTest.cpp
 *
 *  Created on: Aug 20, 2019
 *      Author: thepursuer
 */

#include <gtest/gtest.h>

#include "TripleBufferTestFixture.h"

namespace{

TEST_F(TripleBufferTestFixture, INTUPDATEANDREADTEST){
	int i = 5;
	buf.update(i);
	ASSERT_EQ(5, buf.read());
}

TEST_F(TripleBufferTestFixture, STALEFLAGTEST){
	//Should initialize as stale
	ASSERT_TRUE(buf.isStale());

	int i = 5;
	buf.update(i);
	ASSERT_FALSE(buf.isStale());//Should now be fresh

	buf.read();
	ASSERT_TRUE(buf.isStale());//Now its stale

	buf.update(i + 2);
	ASSERT_FALSE(buf.isStale());//Should now be fresh again
}

}


