#include "stdafx.h"
#include "CppUnitTest.h"
#include"..\algorithm\redblack_bst.h"
#include<string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using algorithmcpp::RedBlackBST;
using std::string;

namespace algorithmtest
{
	TEST_CLASS(RedBlackBSTTests)
	{
	public:

		TEST_METHOD(RedBlackBSTTest1)
		{
			RedBlackBST<string, int> st;
			Assert::IsTrue(st.IsEmpty(), L"", LINE_INFO());

			st.Put("asd",355);
			st.Put("dsd", 25);
			st.Put("esd", 15);
			while (st.Size() > 0) {
				string k = st.Min();
				st.Delete(k);
			}
			string keys[] = { "to", "be", "or", "not", "to", "be", "is", "quest" };
			size_t sz = sizeof(keys) / sizeof(*keys);
			for (size_t i = 0; i < sz; ++i)
				st.Put(keys[i], i);
			Assert::IsTrue(!(st.IsEmpty()) && (st.Size() == 6), L"", LINE_INFO());

			string key = "not";
			Assert::IsTrue(st.Contains(key), L"", LINE_INFO());
			st.Delete(key);
			Assert::IsFalse(st.Contains(key), L"", LINE_INFO());
			Assert::IsFalse(st.Get(key).has_value(), L"", LINE_INFO());

			int value = st.Get("is").value();
			Assert::IsTrue(value == 6, L"", LINE_INFO());
			Assert::IsTrue(st.Select(3) == "quest", L"", LINE_INFO());

			Assert::IsFalse(st.Get("world").has_value(), L"", LINE_INFO());
		}

	};
}
