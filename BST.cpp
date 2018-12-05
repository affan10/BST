#include <iostream>

using namespace std;

class BST_Node
{
	int data;
	BST_Node * LeftChild;
	BST_Node * RightChild;
	BST_Node * Parent;
	
	public:
	void abandon(BST_Node * node)
	{
		if (LeftChild == node)
		{
			LeftChild = NULL;
		}

		else
		{
			RightChild = NULL;
		}

		delete node;
	}

	int successor()
	{
		if (RightChild !=NULL)
		{
			return RightChild->data;
		}

		else
		{
			if (Parent->LeftChild !=NULL && Parent->LeftChild->data == data)
			{
				return Parent->data;
			}

			else
			{
				if (Parent->Parent !=NULL)
				{
					return Parent->Parent->successor();
				}

				else
				{
					return -1;
				}
			}
		}
	}

	void Delete(int value)
	{
		if (value == this->data)
		{
			if (LeftChild !=NULL && RightChild !=NULL)
			{
				int temp = successor();
				Delete(temp);
				this->data = temp;
			}

			else
			{
				if (!(LeftChild !=NULL || RightChild !=NULL))
				{
					Parent->abandon(this);
				}

				else
				{
					BST_Node * temp = this;
					if (RightChild !=NULL)
					{
						if (Parent->data < data)
						{
							Parent->RightChild = temp->RightChild;
						}

						else
						{
							Parent->LeftChild = temp->RightChild;
						}
					}

					else
					{
						if (Parent->data < data)
						{
							Parent->RightChild = temp->LeftChild;
						}

						else
						{
							Parent->LeftChild = temp->LeftChild;
						}
					}

					delete temp;
				}
			}
		}

		else
		{
			if (value < data && LeftChild !=NULL)
			{
				LeftChild->Delete(value);
			}

			else
			{
				if (value > data && RightChild !=NULL)
				{
					RightChild->Delete(value);
				}
			}
		}
	}

	void insert(int value)
	{
		if (value < data)
		{
			if (LeftChild == NULL)
			{
				LeftChild = new BST_Node(value);
				LeftChild->Parent = this;
			}

			else
			{
				LeftChild->insert(value);
			}
		}

		else
		{
			if (RightChild == NULL)
			{
				RightChild = new BST_Node(value);
				RightChild->Parent = this;
			}

			else
			{
				RightChild->insert(value);
			}
		}
	}

	void print()
	{
		if (LeftChild !=NULL)
		{
			LeftChild->print();
		}

		cout << data << "\t";

		if (RightChild !=NULL)
		{
			RightChild->print();
		}

	}

	bool Search(int value)
	{
		bool result = false;
		if (data == value)
		{
			result = true;
		}

		else
		{
			if (!result && value < data)
			{
				if (LeftChild != NULL)
				{
					result = LeftChild->Search(value);
				}
			}

			if (!result && value > data)
			{
				if (RightChild != NULL)
				{
					result = RightChild->Search(value);
				}
			}
		}

		return result;
	}

	BST_Node(int data)
	{
		this->data = data;
		LeftChild = NULL;
		RightChild = NULL;
	}
};

int main()
{
	BST_Node tree(4);
	tree.insert(3);
	tree.insert(8);
	tree.insert(5);
	tree.insert(6);
	tree.insert(1);
	tree.insert(2);
	tree.insert(9);
	tree.insert(0);
	tree.print();
	cout << endl;
	tree.Delete(0);
	tree.print();
	cout << endl;
	tree.Delete(5);
	tree.print();
	cout << endl;
	tree.Delete(8);
	tree.print();
	cout << endl << endl;
	system("pause");
	return 0;
}
