#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_12_list/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestCreateList)
		{
			Node* head = nullptr;
			Node* tail = nullptr;

			Note testPeople[] = {
				{"Doe", "John", "1234567890", {1, 4, 1990}},
				{"Smith", "Alice", "0987654321", {15, 8, 1985}}
			};

			std::istringstream iss("2\nDoe\nJohn\n1234567890\n1 4 1990\nSmith\nAlice\n0987654321\n15 8 1985\n");
			std::cin.rdbuf(iss.rdbuf());

			createList(head, tail);

			Node* current = head;
			for (int i = 0; i < 2; ++i) {
				Assert::AreEqual(testPeople[i].lastName, current->data.lastName);
				Assert::AreEqual(testPeople[i].firstName, current->data.firstName);
				Assert::AreEqual(testPeople[i].phoneNumber, current->data.phoneNumber);
				Assert::AreEqual(testPeople[i].birthDate[0], current->data.birthDate[0]);
				Assert::AreEqual(testPeople[i].birthDate[1], current->data.birthDate[1]);
				Assert::AreEqual(testPeople[i].birthDate[2], current->data.birthDate[2]);
				current = current->next;
			}
		}

	};
}
