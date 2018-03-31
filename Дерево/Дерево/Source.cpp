#include<vector>
template <typename myTip>
class Derevo
{
	struct MultiNode
	{
		myTip data; //тип элементов дерева
		int id; //идентификатор
		MultiNode * parent; //указатель на родительскую структуру
		vector <MultiNode *> children; //контейнер ссылок на потомков
	};
	MultiNode * koren;
	int curr;
	myTip * find(int id)
	{
		return p;
	}
public:
	int addNode(myTip x, int id)
	{ 
		Node * newNode = new Node;
		Node * p = find(id);
		(p->children).assign(newNode);
		newNode->id = ++curr;
		newNode->x = x;
		return curr;
	}
	void del()
	{
		for (int i = curr; i >= 0; i--)
		{
			MultiNode * p = find(i);
			(p->children).~vector;
			delete p;
		}
	}
	Derevo(myTip x)
	{
		koren = new Node;
		koren.data = x;
		curr = 0;
		koren->id = 0;
		koren->parent = NULL;
		koren->children = NULL;
	}
	~Derevo()
	{
		del();
	}
};