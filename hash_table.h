#ifndef HASH_TABLE_H
#define HASH_TABLE_H
/* HASH_TABLE */
template <typename valueType, typename keyType>
class map {
private:
	/* Node */
	struct Node {
		valueType value;
		keyType key;

		Node* next;
	};
	Node* head;
	Node* tail;
	/* Methods */
	Node*		find		(keyType key);
	bool		isKeyIn		(keyType key);
public:
	/* Init */
	map				();
	map				(valueType value, keyType key);
	~map				();
	/* Methods */
	void		include		(valueType value, keyType key);
	valueType	findValue	(keyType key);
	void		destroy		(keyType key);
	void		destroyAll	();
};
/* INIT REALISATION */
template <typename valueType, typename keyType>
map<valueType, keyType>::map() {
	head = nullptr;
	tail = head;
}
template <typename valueType, typename keyType>
map<valueType, keyType>::map(valueType value, keyType key) {
	Node* nNode = new Node();

	nNode->value = value;
	nNode->key = key;
	nNode->next = nullptr;

	head = nNode;
	tail = nNode;
}
template <typename valueType, typename keyType>
map<valueType, keyType>::~map() {
	destroyAll();
}
/* METHODS REALISATION */
template <typename valueType, typename keyType>
void map<valueType, keyType>::include(valueType value, keyType key) {
	if (isKeyIn(key)) { return; }

	Node* nNode = new Node();

	nNode->value = value;
	nNode->key = key;
	nNode->next = nullptr;

	if (head == nullptr || head->key == key) {
		nNode->next = head;
		head = nNode;

		if (tail == nullptr) { tail = nNode; }
	}
	else {
		Node* current = head;

		while (current->next != nullptr && current->next->key == key)
		{
			current = current->next;
		}

		nNode->next = current->next;
		current->next = nNode;
		
		if (nNode->next == nullptr) {
			tail == nNode;
		}
	}
}
template <typename valueType, typename keyType>
bool map<valueType, keyType>::isKeyIn(keyType key) {
	Node* current = head;

	while (current != nullptr) {
		if (current->key == key) return true;

		current = current->next;
	}

	return false;
}
template <typename valueType, typename keyType>
typename map<valueType, keyType>::Node* map<valueType, keyType>::find(keyType key) {
	Node* current = head;

	while (current != nullptr)
	{
		if (current->key == key) { return current; }
		current = current->next;
	}

	delete current;
	return nullptr;
}
template <typename valueType, typename keyType>
valueType map<typename valueType, typename keyType>::findValue(keyType key) {
	Node* current = tail;

	while (current != nullptr) {
		if (current->key == key) { return current->value; }
		current = current->next;
	}

	delete current;
}
template <typename valueType, typename keyType>
void map<valueType, keyType>::destroy(keyType key) {
	Node* node_to_delete = find(key);
	if (node_to_delete != nullptr) {
		Node* current = head;
		Node* previous = nullptr;

		while (current != nullptr) {
			if (current == node_to_delete) {
				if (previous == nullptr) {
					head = current->next;
				}
				else {
					previous->next = current->next;
				}
				delete current;
				return;
			}
			previous = current;
			current = current->next;
		}
	}
}
template <typename valueType, typename keyType>
void map<valueType, keyType>::destroyAll() {
	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = nullptr;
	tail = nullptr;
}
/* !HASH_TABLE_H */
#endif
