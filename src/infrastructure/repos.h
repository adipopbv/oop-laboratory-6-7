#include <iostream>

template <typename ElementType>
class Repo
{
	private:
		/// Implementation of a simple linked list for the repo
		struct RepoNode
		{
			ElementType element; // the value of the element iteself
			RepoNode* next; // reference to the next element
		};

		/// The head of the repo
		RepoNode* head;

		/**
		 * Gets the node at the given index
		 *
		 * @param index An index
		 * @returns The node at index
		 */
		RepoNode* NodeAtIndex(int index)
		{
			if (this->Empty()) // throw exception if repo is empty
				throw std::string("Index out of bounds!");
			RepoNode* currentNode = this->head;
			for (int i = 0; i < index; i++) // iterating nodes until the requested one
			{
				// throw exception if the index is out of bounds
				if (currentNode == NULL)
					throw std::string("Index out of bounds!");
				if (currentNode->next == NULL)
					throw std::string("Index out of bounds!");

				currentNode = currentNode->next; // step to the next node
			}
			return currentNode; // return reference to the node
		}

	public:
		/// Repo constructor
		Repo()
		{
			this->head = NULL; // making the list empty
		}
		
		/// Repo destructor
		~Repo()
		{
			RepoNode* currentNode = this->head;
			while (currentNode) // iterating all nodes
			{
				RepoNode* nextNode = currentNode->next; // getting the next node

				// freeing current node
				currentNode->next = NULL;
				delete currentNode;

				currentNode = nextNode; // stepping to the next node
			}
		}
		
		/**
		 * Overloading the subscripting operator
		 * Gets the element at a given index
		 *
		 * @param index The index of the element to be returned from the repo
		 * @returns The element at the index position
		 */
		ElementType &operator[](int index)
		{
			if (this->Empty()) // throw exception if repo is empty
				throw std::string("Index out of bounds!");
			RepoNode* currentNode = this->head;
			for (int i = 0; i < index; i++) // iterating nodes until the requested one
			{
				// throw exception if the index is out of bounds
				if (currentNode == NULL)
					throw std::string("Index out of bounds!");
				if (currentNode->next == NULL)
					throw std::string("Index out of bounds!");

				currentNode = currentNode->next; // step to the next node
			}
			return currentNode->element; // return reference to the element
		}

		/**
		 * Gets the length of the repo
		 *
		 * @returns Number of elements
		 */
		int Size() const
		{
			RepoNode* currentNode = this->head;
			int count = 0;
			while (currentNode != NULL) // iterating all nodes
			{
				count++; // counting iterated nodes
				currentNode = currentNode->next;
			}
			return count;
		}

		/**
		 * Verifies the emptiness of the repo
		 *
		 * @returns True if list is empty of false otherwise
		 */
		bool Empty() const
		{
			return (this->head == NULL) ? true : false; // repo empty if there are no nodes
		}

		/**
		 * Adds element pointer to the begining of the repo
		 *
		 * @param element An element
		 * @param begining Should the adding operation be done at the begining of the list or at the end, defaults to false
		 */
		void Add(ElementType element, bool begining = false)
		{
			// making a new node
			RepoNode* newNode = new RepoNode();
			newNode->element = element;
			newNode->next = NULL;

			if (this->Empty())
			{ head = newNode; } // set the first node to the given one
			else if (begining) // add to the begining of the repo
			{
				newNode->next = this->head; // making the new node's next element the repo's old head node
				this->head = newNode; // making the new node the head of the repo
			}
			else // add to the end
			{
				this->NodeAtIndex(this->Size() - 1)->next = newNode; // attaching the new node to the end of the repo
			}
		}

		/**
		 * Inserts an element at the given index
		 *
		 * @param element The element to be inserted
		 * @param index The position for insertion
		 * @throws Exception if index is out of bounds
		 */
		void Insert(ElementType element, int index)
		{
			// making a new node
			RepoNode* newNode = new RepoNode();
			newNode->element = element;
			newNode->next = NULL;

			if (index == 0) // adding from the begining
			{
				newNode->next = this->head;
				this->head = newNode;
			}
			else // inserting at index
			{
				newNode->next = this->NodeAtIndex(index - 1)->next;
				this->NodeAtIndex(index - 1)->next = newNode;
			}
		}

		/**
		 * Erases the element from the given position
		 *
		 * @param index The index of the element to be removed
		 * @throws Exception if index is out of bounds
		 */
		void Erase(int index)
		{
			// getting the node to be erased
			RepoNode* node = this->NodeAtIndex(index);
			
			if (index == 0)
			{ this->head = this->head->next; } // exclude the first node
			else
			{ this->NodeAtIndex(index - 1)->next = this->NodeAtIndex(index)->next; } // exclude any other node
			
			// erase the node
			node->next = NULL;
			delete node;
		}
};
