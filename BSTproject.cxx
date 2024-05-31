#include <iostream>
using namespace std;

void err(int &num)
{
	while (!(cin >> num) || cin.peek() != '\n')
	{
		cout << "\n \t\t--- ERROR ! ---\n\t A number must be entered.\n\n Enter again : ";

		cin.clear();

		cin.ignore(100, '\n');
	}
}

const int s = 100;

class STACK
{
  private:
	int top;
	int list[s];

  public:
	STACK()
	{
		top = -1;
	}

	bool isFull()
	{
		if (top == s - 1)
			return true;
		else
			return false;
	}

	bool isEmpty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}

	void push(int el)
	{
		if (isFull())
			cout << "\n Stack is full!";
		else
			list[top + 1] = el;
		top++;
	}

	int pop()
	{
		int el;
		if (isEmpty())
		{
			cout << "\n Stack is empty! ";
			return 0;
		}
		else
		{
			el = list[top];
			top--;
			return el;
		}
	}

	int topv()
	{
		return top;
	}
};

class Node
{
  public:
	int data;
	Node *left;
	Node *right;

	Node(int value)
	{
		data = value;
		left = 0;
		right = 0;
	}
};

class BST
{
  private:
	Node *root;

	void add(int el, Node *&n)
	{
		if (n == 0)
		{
			n = new Node(el);
			cout << " \n\t--- Value " << el << " added --- \n";
			return;
		}
		else if (el < n->data)
		{
			add(el, n->left);
		}
		else if (el > n->data)
		{
			add(el, n->right);
		}
		else
		{
			cout << "\n Sorry, the value " << el << " exists already\n"
													"\n      --- Value not added ---\n";
			return;
		}
	}

	void preOrder(Node *n)

	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n";
			return;
		}
		else
		{
			if (n == 0)
				return;
			cout << "  " << n->data << "  ";
			preOrder(n->left);
			preOrder(n->right);
		}
	}

	void inOrder(Node *n)

	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n";
			return;
		}
		else
		{
			if (n == 0)
				return;
			inOrder(n->left);
			cout << "  " << n->data << "  ";
			inOrder(n->right);
		}
	}

	void postOrder(Node *n)

	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n";
			return;
		}
		else
		{
			if (n == 0)
				return;
			postOrder(n->left);
			postOrder(n->right);
			cout << "  " << n->data << "  ";
		}
	}

	bool search(int el, Node *n)
	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n";
			return false;
		}

		if (n == 0)
		{
			cout << "\n\t --- Value " << el << " Not Found ---\n";
			return false;
		}
		else if (n->data == el)
		{
			cout << "\n\t --- Value " << el << " Found ---\n";
			return true;
		}
		else if (el < n->data)
			return search(el, n->left);
		else
			return search(el, n->right);
	}

	Node *findMax(Node *n)
	{
		if (n == 0 || n->right == 0)
			return n;
		else
			return findMax(n->right);
	}

	Node *findMin(Node *n)
	{
		if (n == 0 || n->left == 0)
			return n;
		else
			return findMin(n->left);
	}

	void count(int &c, Node *n)

	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n\n";
			return;
		}
		else
		{
			c++;
			if (n->right != 0)
			{
				count(c, n->right);
			}
			if (n->left != 0)
			{
				count(c, n->left);
			}
		}
	}

	void countLeaf(int &c, Node *n)

	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n\n";
			return;
		}

		if (n->left == 0 && n->right == 0)
		{
			c++;
		}
		if (n->left != 0)
		{
			countLeaf(c, n->left);
		}
		if (n->right != 0)
			countLeaf(c, n->right);
	}

	bool sadd(int el, Node *&n)
	{
		if (n == 0)
		{
			n = new Node(el);
			return true;
		}
		else if (el < n->data)
		{
			return sadd(el, n->left);
		}
		else if (el > n->data)
		{
			return sadd(el, n->right);
		}
		else
		{
			return false;
		}
	}

	void edit(int el, int ed, Node *&n)
	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ! ---\n";
			return;
		}

		if (n == 0)
		{
			cout << "\n Value " << el << " does not exist in the tree\n";
			return;
		}
		if (n->data == el)
		{
			if (sadd(ed, root))
			{
				del(el);
				system("cls");
				cout << "\n Value " << el << " edited to " << ed << endl;
			}
			else
			{
				cout << "\n Value " << ed << " already exists in the tree \n"
											 "\n      --- Value not edited ---\n";
			}
			return;
		}
		if (el < n->data)
			edit(el, ed, n->left);
		if (el >= n->data)
			edit(el, ed, n->right);
	}

	void del(int el, Node *&n)
	{
		if (root == 0)
		{
			cout << "\n\t --- Tree is empty! ---\n";
			return;
		}
		if (n == 0)
		{
			cout << "\n\tValue " << el << " does not exist in the tree!\n";
			return;
		}

		if (el > n->data)
			del(el, n->right);
		else if (el < n->data)
			del(el, n->left);
		else
		{
			if (n->left == 0 && n->right == 0)
			{
				delete n;
				n = 0;
				cout << "\n\t --- Value " << el << " deleted ---\n";
				return;
			}
			else if (n->left == 0 && n->right != 0)
			{
				n = n->right;
				cout << "\n\t --- Value " << el << " deleted ---\n";
				return;
			}
			else if (n->right == 0 && n->left != 0)
			{
				n = n->left;
				cout << "\n\t --- Value " << el << " deleted ---\n";
				return;
			}
			else
			{
				n->data = findMax(n->left)->data;
				del(findMax(n->left)->data, n->left);
				system("cls");
				cout << "\n\t --- Value " << el << " deleted ---\n";
				return;
			}
		}
	}

	void deleteAll()
	{
		root = 0;
	}

	Node *findNode(int el, Node *n)
	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ---\n";
			return 0;
		}

		if (n == 0)
		{
			cout << "\n\t--- Node not found ---\n";
			return 0;
		}

		if (n->data == el)
			return n;
		else if (el > n->data)
			return findNode(el, n->right);
		else if (el < n->data)
			return findNode(el, n->left);
	}

	void print_child(int el, Node *&n)
	{
		Node *fn = findNode(el, root);
		if (fn == 0)
			return;

		if (fn->right == 0 && fn->left == 0)
		{
			cout << "\n\t--- Node has no children ---\n";
		}
		if (fn->right != 0)
		{
			cout << "\n Right child is : " << fn->right->data << endl;
			if (fn->left == 0)
				cout << "\n No left child \n";
		}
		if (fn->left != 0)
		{
			if (fn->right == 0)
				cout << "\n No right child \n";
			cout << "\n Left child is : " << fn->left->data << endl;
		}
	}

	void print_root(Node *&n)
	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ---\n";
			return;
		}

		if (root->left == 0 && root->right == 0)
			cout << "  " << n->data << "  ";
		if (n->right != 0 || n->left != 0)
		{
			cout << "  " << n->data << "  ";

			if (n->right != 0)
				print_root(n->right);

			if (n->left != 0)
				print_root(n->left);
		}
	}

	void toStack(STACK &s, Node *&n)
	{
		if (root == 0)
		{
			cout << "\n\t--- Tree is empty ---\n";
			return;
		}
		else
		{
			if (n == 0)
				return;
			toStack(s, n->right);
			s.push(n->data);
			toStack(s, n->left);
		}
	}

  public:
	BST()
	{
		root = 0;
	}

	void add(int el)
	{
		cout << endl;
		add(el, root);
		cout << endl;
	}

	void preOrder()
	{
		cout << endl;
		preOrder(root);
		cout << endl;
	}

	void inOrder()
	{
		cout << endl;
		inOrder(root);
		cout << endl;
	}

	void postOrder()
	{
		cout << endl;
		postOrder(root);
		cout << endl;
	}

	bool search(int el)
	{
		return search(el, root);
	}

	bool findMax()
	{
		if (findMax(root) != 0)
		{
			cout << " Max value is : " << findMax(root)->data;
			return true;
		}
		else
		{
			cout << "\n\t --- Tree is empty ! ---\n";
			return false;
		}
	}

	int findMin()
	{
		if (findMin(root) != 0)
		{
			cout << " Min value is : " << findMin(root)->data;
			return true;
		}
		else
		{
			cout << "\n\t--- Tree is empty ! ---\n";
			return false;
		}
	}

	void count()
	{
		int c = 0;
		count(c, root);
		cout << "\n Node Count = " << c;
	}

	void countLeaf()
	{
		int c = 0;
		countLeaf(c, root);
		cout << "\n Leaf Count = " << c;
	}

	void edit(int el, int ed)
	{
		edit(el, ed, root);
	}

	void del(int el)
	{
		del(el, root);
	}

	void delAll()
	{
		deleteAll();
	}

	void print_child(int el)
	{
		print_child(el, root);
	}

	void print_root()
	{
		cout << endl;
		print_root(root);
		cout << endl;
	}

	void toStack()
	{
		STACK s;
		toStack(s, root);
		int loop = s.topv();
		cout << endl;
		for (int i = 0; i <= loop; i++)
		{
			cout << "  " << s.pop() << "  ";
		}
		cout << endl;
	}
};

int main()
{
	system("color e0");

	int bx;
	int choice;
	BST tree;

start:

	cout << "------------------\n\n"
			" 1 ] Show Data\n\n"
			" 2 ] Add Data\n\n"
			" 3 ] Edit Data\n\n"
			" 4 ] Delete Data\n\n"
			" 5 ] Find Data\n\n"
			" 6 ] Count Data\n\n"
			" 7 ] Exit\n\n------------------\n\n"
			" Choose a number : ";
	err(choice);

	system("cls");
	switch (choice)
	{
	case 1:

	show:
		cout << "---------------------------------\n\n"
				" 1 ] Print nodes in pre_order\n\n"
				" 2 ] Print nodes in in_order\n\n"
				" 3 ] Print nodes in post_order \n\n"
				" 4 ] Print node children\n \n"
				" 5 ] Print roots\n \n"
				" 6 ] Tree_stack convert then pop\n\n"
				" 7 ] Go back\n\n"
				"---------------------------------\n\n"
				" Choose a number : ";
		err(choice);
		system("cls");
		if (choice == 1)
			tree.preOrder();
		else if (choice == 2)
			tree.inOrder();
		else if (choice == 3)
			tree.postOrder();
		else if (choice == 4)
		{
			cout << "\n------------------------------------------------------------\n\n"
					" >> Enter value of node you want to print it's children : ";
			int el;
			err(el);
			tree.print_child(el);
		}
		else if (choice == 5)
			tree.print_root();
		else if (choice == 6)
			tree.toStack();
		else if (choice == 7)
			goto start;
		else
		{
			system("cls");
			cout << "\n\n \t --- Wrong number! ---\n\n";
			goto show;
		}
	ag:
		cout << "\n--------------\n\n"
				" 1 ] Go back\n\n"
				" 2 ] Exit\n\n"
				"--------------\n\n"
				" Choose a number : ";
		err(bx);
		if (bx == 1)
		{
			system("cls");
			goto show;
		}
		else if (bx == 2)
		{
			system("cls");
			cout << "\n\n\n\t --- GOOD BYE ---\n\n";
		}
		else
		{
			system("cls");
			cout << "\n\n\t --- Wrong number! --- \n\n";
			goto ag;
		}

		break;

	case 2:

		do
		{
			system("cls");
			cout << "\n--------------------------------\n\n >> Enter an integer to add : ";
			int num;
			err(num);
			tree.add(num);

		aba:

			cout << "\n-------------\n\n"
					" 1 ] Add more\n\n"
					" 2 ] Go back \n\n"
					"--------------\n\n "
					" Choose a number : ";
			err(bx);

			if (bx == 1)
				bx = 1;
			else if (bx == 2)
			{
				system("cls");
				goto start;
			}
			else
			{
				system("cls");
				cout << "\n\n\tWrong number!\n\n";
				goto aba;
			}

		} while (bx == 1);
		break;

	case 3:

		int num1, num2;
		do
		{
			system("cls");
			cout << "\n--------------------------------------------\n\n >> Enter the integer you want to edit : ";
			err(num1);
			cout << "\n >> Enter replace value : ";
			err(num2);
			system("cls");
			cout << "\n Edit number " << num1 << " to " << num2 << " ?\n"
																   "----------------\n\n"
																   " 1 ] Edit\n\n"
																   " 2 ] Cancel\n\n"
																   "----------------\n\n"
																   "Choose a number : ";
			err(choice);
			system("cls");
			if (choice == 1)
			{
				tree.edit(num1, num2);
			}
			else
			{
				cout << " \n\t--- Editing canceled ---\n\n";
			}

		eba:
			cout << "\n---------------------\n\n"
					" 1 ] Edit more\n\n"
					" 2 ] Go back\n\n"
					"---------------------\n\n"
					" Choose a number : ";
			err(bx);

			if (bx == 1)
				bx = 1;
			else if (bx == 2)
			{
				system("cls");
				goto start;
			}
			else
			{
				system("cls");
				cout << "\n\n\t Wrong number!\n\n";
				goto eba;
			}

		} while (bx == 1);

		break;

	case 4:

		system("cls");
	dl:
		cout << "\n--------------------"
				"\n\n 1 ] Delete an integer\n\n"
				" 2 ] Delete all data\n\n"
				" 3 ] Go back\n\n"
				"--------------------\n"
				" Choose a number : ";
		err(choice);

		if (choice == 1)
		{
		dm:
			system("cls");
			cout << "\n-----------------------------------\n >> Enter an integer to delete : ";
			int delnum;
			err(delnum);
			system("cls");
		dn:
			cout << "\n Delete number " << delnum << " from tree ?\n"
													 "----------------\n\n"
													 " 1 ] Delete\n\n"
													 " 2 ] Cancel\n\n"
													 "----------------\n\n"
													 "Choose a number : ";
			err(choice);
			system("cls");
			if (choice == 1)
			{
				tree.del(delnum);
			}
			else if (choice == 2)
			{
				system("cls");
				cout << " \n\t--- Deleting canceled ---\n\n";
			}
			else
			{
				cout << "\n\t--- Wrong numner! ---\n";
				goto dn;
			}

		dba:
			cout << "\n---------------------\n\n"
					" 1 ] Delete more\n\n"
					" 2 ] Go back\n\n"
					"---------------------\n\n"
					" Choose a number : ";
			err(bx);

			if (bx == 1)
				goto dm;
			else if (bx == 2)
			{
				system("cls");
				goto dl;
			}
			else
			{
				system("cls");
				cout << "\n\n\t Wrong number!\n\n";
				goto dba;
			}
		}
		else if (choice == 2)
		{
			system("cls");
		da:
			cout << "\n Confirm deleting all data ?\n"
					"---------------------------\n\n"
					" 1 ] Delete \n\n"
					" 2 ] Cancel\n\n"
					"---------------------------\n"
					" Choose a number : ";
			err(choice);
			system("cls");
			if (choice == 1)
			{
				tree.delAll();
				cout << "\n\t--- All data deleted ---\n";
			}
			else if (choice == 2)
				cout << "\n\t--- Deleting canceled ---\n";
			else
			{
				system("cls");
				cout << "\n\t--- Wrong number ---\n";
				goto da;
			}

		dab:
			cout << "\n---------------------\n\n"
					" 1 ] Go back\n\n"
					" 2 ] Exit\n\n"
					"---------------------\n\n"
					" Choose a number : ";
			err(bx);

			if (bx == 1)
			{
				system("cls");
				goto start;
			}
			else if (bx == 2)
			{
				system("cls");
				cout << "\n\n \t --- BYEBYE ---\n\n";
			}
			else
			{
				system("cls");
				cout << "\n\n\t Wrong number!\n\n";
				goto dab;
			}
		}
		else if (choice == 3)
		{
			system("cls");
			goto start;
		}
		else
		{
			system("cls");
			cout << "\n\n\t Wrong number!\n\n";
			goto dl;
		}

		break;

	case 5:
	find:

		cout << "\n-----------------------\n\n"
				" 1 ] Find an integer\n\n"
				" 2 ] Find max integer\n\n"
				" 3 ] Find min integer\n\n"
				" 4 ] Go back\n\n"
				"-----------------------\n\n"
				" Choose a number : ";

		err(choice);
		system("cls");
		if (choice == 1)
		{
		search:
			cout << "\n---------------------------------------\n\n >> Enter an integer to search for : ";
			int searchNum;
			err(searchNum);
			tree.search(searchNum);
		sb:
			cout << "\n------------------\n\n"
					" 1 ] Search more\n\n"
					" 2 ] Go back\n \n"
					"------------------\n\n"
					" Choose a number : ";
			err(choice);
			if (choice == 1)
			{
				system("cls");
				goto search;
			}
			else if (choice == 2)
			{
				system("cls");
				goto find;
			}
			else
			{
				system("cls");
				cout << "\n\t--- Wrong number ---\n";
				goto sb;
			}
		}
		else if (choice == 2)
		{
			cout << "\n -----------------\n\n";
			tree.findMax();
		}
		else if (choice == 3)
		{
			cout << "\n -----------------\n\n";
			tree.findMin();
		}
		else if (choice == 4)
		{
			system("cls");
			goto start;
		}
		else
		{
			system("cls");
			cout << "\n\n\t --- Wrong number! ---\n\n";
			goto find;
		}

	fba:
		cout << "\n\n ----------------- \n\n"
				" 1 ] Go back\n\n"
				" 2 ] Exit\n\n"
				"-----------------\n\n "
				" Choose a number : ";
		err(bx);
		if (bx == 1)
		{
			system("cls");
			goto find;
		}
		else if (bx == 2)
		{
			system("cls");
			cout << "\n\n \t --- BYEBYE ---\n\n";
		}
		else
		{
			system("cls");
			cout << "\t--- Wrong number! ---\n\n";
			goto fba;
		}

		break;

	case 6:
	count:
		system("cls");
		cout << "\n------------------"
				"\n\n"
				" 1 ] Node count\n\n"
				" 2 ] Leaf count\n\n"
				" 3 ] Go back\n\n"
				"------------------\n\n"
				" Choose a number : ";

		err(choice);
		system("cls");
		if (choice == 1)
		{
			tree.count();
			cout << endl;
		}
		else if (choice == 2)
		{
			tree.countLeaf();
			cout << endl;
		}
		else if (choice == 3)
			goto start;
		else
		{
			cout << "\n\n\t --- Wrong number! ---\n\n";
			goto count;
		}

		cout << "\n ----------------- \n\n"
				" 1 ] Go back\n\n"
				" 2 ] Exit\n\n"
				"-----------------\n\n "
				" Choose a number : ";
		err(bx);
		if (bx == 1)
		{
			goto count;
		}
		else if (bx == 2)
			cout << "\n\n \t --- BYEBYE ---\n\n";
		else
		{
			cout << "\t--- Wrong number! ---\n\n";
			goto fba;
		}

		break;

	case 7:
		cout << "\n\n \t --- BYEBYE ---\n\n";
		break;

	default:
		system("cls");
		cout << "\n\t --- Wrong number ---\n\n";
		goto start;
		break;
	}
}
