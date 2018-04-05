#include<vector>
#include <iostream>
using namespace std;

template <typename myTip>
class Derevo
{
	struct MultiNode
	{
		myTip data; //тип элементов дерева
		int id; //идентификатор
		MultiNode * parent; //указатель на родительскую структуру
		vector <MultiNode *> *children; //контейнер ссылок на потомков
	};
	int curr;
	MultiNode * find(int id1, MultiNode * ukaz)
	{
		MultiNode * temp = NULL;
			if ((ukaz->id) == id1)
				return ukaz;
			else
			{
				if ((ukaz->children) == NULL)
					return NULL;
				for (int i = 0; i <= (ukaz->children)->size() - 1; i++)
				{
					temp = find(id1, (*(ukaz->children))[i]);
					if (temp != NULL)
						return temp;
				}
				return NULL;
			}
	}
public:
	MultiNode * koren;
	int addNode(myTip x, int id)
	{ 
		MultiNode * newNode = new MultiNode;
		MultiNode * p = find(id, koren);
		if (p->children == NULL)
			p->children = new vector<MultiNode*>;
		(p->children)->push_back(newNode);
		newNode->parent = p;
		newNode->id = ++curr;
		newNode->data = x;
		newNode->children = NULL;
		cout << "Идентификатор этого элемента = " << curr << endl;
		return curr;
	}
	void del()
	{
		for (int i = curr; i >= 0; i--)
		{
			MultiNode * p = find(i, koren);
			if (p->parent != NULL)
			{
				((p->parent)->children)->pop_back();
				if (((p->parent)->children)->size() == 0)
					(p->parent)->children = NULL;
			}
			delete p;
		}
		curr = -1;
	}
	void list(MultiNode * ukaz)
	{
		if (ukaz == NULL)
		{
			cout << "Дерево пусто =(" << endl;
			return;
		}
		if ((ukaz->children) == NULL)
		{
			cout << ukaz->data << ' ';
		}
		else
		{
			for (int i = 0; i <= (ukaz->children)->size() - 1; i++)
				list((*(ukaz->children))[i]);
		};
	}
	Derevo(myTip x)
	{
		koren = new MultiNode;
		koren->data = x;
		curr = 0;
		koren->id = 0;
		koren->parent = NULL;
		koren->children = NULL;
		cout << "Идентификатор корня = 0" << endl;
	}
	~Derevo()
	{
		del();
	}
};

int main()
{
	setlocale(0, "");
	int x;
	cout << "Введите корень дерева" << endl;
	cin >> x;
	Derevo<int> tree(x);
	cout << "Введите наследника дерева" << endl;
	cin >> x;
	tree.addNode(x, 0);
	cout << "Введите наследника дерева" << endl;
	cin >> x;
	tree.addNode(x, 0);
	cout << "Введите наследника дерева" << endl;
	cin >> x;
	tree.addNode(x, 0);
	cout << "Введите наследника для элемента 1" << endl;
	cin >> x;
	tree.addNode(x, 1);
	cout << "Введите наследника для элемента 1" << endl;
	cin >> x;
	tree.addNode(x, 1);
	cout << "Введите наследника для элемента 1" << endl;
	cin >> x;
	tree.addNode(x, 1);
	cout << "Введите наследника для элемента 1" << endl;
	cin >> x;
	tree.addNode(x, 1);
	cout << "Введите наследника для элемента 2" << endl;
	cin >> x;
	tree.addNode(x, 2);
	cout << "Введите наследника для элемента 2" << endl;
	cin >> x;
	tree.addNode(x, 2);
	cout << "Введите наследника для элемента 3" << endl;
	cin >> x;
	tree.addNode(x, 3);
	tree.list(tree.koren);
	cout << endl;
	return 0;
}