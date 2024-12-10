#include "list.h"
#include <iostream>
using namespace std;
list::list()
{
	head = tail = nullptr;
	size = 0;
}

void list::push_back(int v)
{

	if (head && tail != nullptr) {
		Node* new_node = new Node(v, head);
		tail->next = new_node;
		tail = new_node;
	}
	else {
		Node* new_node = new Node(v);
		head = new_node;
		tail = new_node;
	}
	size++;
}

void list::push_front(int v)
{
	if (head != nullptr) {
		Node* new_node = new Node(head, v);
		head->prev = new_node;
		head = new_node;
	}
	else {
		Node* new_node = new Node(v);
		head = new_node;
	}
	size++;
}

list::list(const list& obj)
	:head(nullptr), tail(nullptr), size(0)
{

	if (obj.size == 0) {
		return;
	}
	Node* current = obj.head;
	Node* x;
	Node* y = new Node(current->value);
	head = y;
	tail = y;
	current = current->next;
	while (current) {
		x = y;
		y = new Node(current->value, x);
		x->next = y;
		tail = y;
		current = current->next;
		size++;
	}
}

void list::pop_back() {
	if (!tail) return;

	Node* to_delete = tail;
	if (tail->prev) {
		tail = tail->prev;
		tail->next = nullptr;
	}
	else {
		head = tail = nullptr;
	}
	delete to_delete;
	size--;
}

void list::pop_front() {
	if (!head) return;

	Node* to_delete = head;
	if (head->next) {
		head = head->next;
		head->prev = nullptr;
	}
	else {
		head = tail = nullptr;
	}
	delete to_delete;
	size--;
}

void list::reverse() {
	if (!head) return;

	Node* current = head;
	Node* temp = nullptr;
	tail = head;

	while (current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp) {
		head = temp->prev;
	}
}

list::~list()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
		cout << "DESTRUCTOR";
	}
	size = 0;
	head = tail = nullptr;
}

void list::operator=(const list& obj)
{

	if (obj.size == 0) {
		return;
	}
	Node* current = obj.head;
	Node* x;
	Node* y = new Node(current->value);
	head = y;
	tail = y;
	current = current->next;
	while (current) {
		x = y;
		y = new Node(current->value, x);
		x->next = y;
		tail = y;
		current = current->next;
		size++;
	}
}

int list::operator[](int index)
{
	Node* current = head;
	for (size_t i = 0; i < index; i++)
	{
		current = current->next;
	}
	return current->value;
}

bool list::insert(int index, int value)
{
	if (index < 0 || index>size - 1) {
		return false;
	}
	Node* current = head;
	Node* new_node = new Node(value);
	if (index == size)
	{
		new_node->prev = tail;
		tail->next = new_node;
		tail = new_node;
		return true;
		size++;
	}
	for (int i = 0; i < index; i++)
	{
		current = current->next;
	}
	if (current->prev) {
		new_node->next = current;
		current->prev = new_node;
	}
	else {
		head = new_node;
	}
	new_node->next = current;
	current->prev = new_node;


	size++;
}

int list::replace(int key, int value)
{
	int count = 0;
	Node* current = head;
	while (current)
	{
		if (current->value == key) {
			current->value = value;
			count++;
		}
		current = current->next;
	}
	return count;
}

int list::replace(bool(*predicate)(int value), int key, int value)
{
	int count = 0;
	Node* current = head;
	while (current)
	{
		if (predicate(current->value)) {
			current->value = value;
			count++;
		}
		current = current->next;
	}
	return count;
}

int list::back() const
{
	if (tail) {
		return tail->value;
	}
}

int list::front() const
{
	if (head) {
		return head->value;
	}
}

void list::show() const
{
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->value << '\t';
		current = current->next;
	}
	cout << endl;
}

list& list::operator+(list& obj)
{
	this->tail->next = obj.head;
	return*this;
}

list* list::operator*(list& obj)
{
	List temp;
	return nullptr;
}

void list::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	size = 0;
	head = tail = nullptr;
	cout << "All Cleared";
}
