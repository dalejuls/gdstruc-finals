#include <iostream>
#include <string>
#include "UnorderedArray.h"
#include "Stack.h"
#include "Queue.h"
#include "UnorderedArray.h"
#include <conio.h>

using namespace std;


void push(Queue<int>& queue, Stack<int>& stack, int val)
{
	queue.push(val);
	stack.push(val);
}


void pop(Queue<int>& queue, Stack<int>& stack)
{
	queue.pop();
	stack.pop();
}

void printAllAndEmpty(Queue<int>& queue, Stack<int>& stack)
{
	cout << "Queue elements:\n";
	while (!queue.isEmpty())
	{
		cout << queue.top() << endl;
		queue.pop();
	}

	cout << "Stack elements:\n";
	while (!stack.isEmpty())
	{
		cout << stack.top() << endl;
		stack.pop();
	}
}

int getDecision() {
	int decision;

	cout << "What do you want to do?" << endl;
	cout << "1 - Push elements\n2 - Pop elements\n3 - Print everything then empty set" << endl;
	cin >> decision;
	return decision;
}

void main()
{


	cout << "Enter size for element sets: ";
	int size;
	cin >> size;
	Queue<int> queue(size);
	Stack<int> stack(size);

	cout << "\n\n";

	while (1)
	{
		switch (getDecision())
		{
		case 1:
			int input;
			cout << "\n\nEnter number: "; 
			cin >> input;
			push(queue, stack, input);
			break;
		case 2:
			cout << "\n\nYou have popped the front elements.\n";
			pop(queue, stack);
			break;
		case 3:
			printAllAndEmpty(queue, stack);
			cout << "Both queue and stack are emptied out." << endl;
			break;
		}

		if (!queue.isEmpty() && !stack.isEmpty())
			cout << "\n\nTop element of sets:\nQueue: " << queue.top() << "\nStack: " << stack.top() << endl;
		system("pause");
		system("cls");
	}

	//for (int i = 0; i < size; i++)
	//{
	//	cout << "Enter element " << i << ": ";
	//	int input;
	//	cin >> input;
	//	queue.push(input);
	//	stack.push(input);
	//}

	//cout << "Top for Queue: " << endl;
	//cout << queue.top() << endl;
	//cout << "Top for Stack: " << endl;
	//cout << stack.top() << endl;

	//queue.pop();
	//stack.pop();

	//while (!queue.isEmpty())
	//{
	//	cout << "\n\nPress enter to pop" << endl;
	//	_getch();
	//	system("cls");

	//	cout << "Top for Queue: " << endl;
	//	cout << queue.top() << endl;
	//	cout << "Top for Stack: " << endl;
	//	cout << stack.top() << endl;
	//	queue.pop();
	//	stack.pop();
	//}

	system("pause");
}