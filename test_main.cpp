#include "lib.h"

#define BOOST_TEST_MODULE test_main

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(test_split_empty) {
	const string in_string = "";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 1);
}

BOOST_AUTO_TEST_CASE(test_split_one) {
	const string in_string = "word";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 1);
	BOOST_CHECK_EQUAL(out[0], "word");
}

BOOST_AUTO_TEST_CASE(test_split_two) {
	const string in_string = "word1.word2";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 2);
	BOOST_CHECK_EQUAL(out[0], "word1");
	BOOST_CHECK_EQUAL(out[1], "word2");
}

BOOST_AUTO_TEST_CASE(test_split_only_delim) {
	const string in_string = "word1.word2.word3";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 3);
	BOOST_CHECK_EQUAL(out[0], "word1");
	BOOST_CHECK_EQUAL(out[1], "word2");
	BOOST_CHECK_EQUAL(out[2], "word3");
}

BOOST_AUTO_TEST_CASE(test_split_delim_one) {
	const string in_string = ".word";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 2);
	BOOST_CHECK(out[0].empty());
	BOOST_CHECK_EQUAL(out[1], "word");
}

BOOST_AUTO_TEST_CASE(test_split_one_delim) {
	const string in_string = "word.";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 2);
	BOOST_CHECK_EQUAL(out[0], "word");
	BOOST_CHECK(out[1].empty());
}

BOOST_AUTO_TEST_CASE(test_split_four_one_at_a_time) {
	// const string in_string = "a.a.a.a";
	const string in_string = "1.1.234.8";
	auto out = str::split(in_string, '.');
	BOOST_CHECK_EQUAL(out.size(), 4);
	BOOST_CHECK_EQUAL(out[0], "1");
	BOOST_CHECK_EQUAL(out[1], "1");
	BOOST_CHECK_EQUAL(out[2], "234");
	BOOST_CHECK_EQUAL(out[3], "8");
}

BOOST_AUTO_TEST_SUITE_END()
