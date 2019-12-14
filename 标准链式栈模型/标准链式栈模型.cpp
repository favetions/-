#include<iostream>	
using namespace std;
struct node
{
	string data;
	node* next;
};
node createstack() {
	node *temp = new node;
	if (temp == NULL) {
		cout << "创建失败" << endl;
	}
	else
	{
		temp->next = NULL;
		return *temp;
	}
}
void push(node *temp) {
	node *temp2 = new node;
	temp2->data = temp->data;
	cout << endl<<"请输入元素：";
	cin >> temp->data;
	temp2->next = temp->next;
	temp->next = temp2;
	cout <<endl<<"入栈成功"<< endl;
	system("pause");
}
node* pop(node* temp) {
	if (temp->next == NULL) {
		cout << "栈已空，无法出栈" << endl;
		return temp;
	}
	else
	{
		cout <<endl<<"元素: " << temp->data << " 正在出栈" << endl;
		temp = temp->next;
		cout << "出栈成功" << endl;
		system("pause");
		return temp;
	}
}
void print(node *temp) {
	if (temp->next==NULL)
	{
		cout << " 栈尾" << endl;
		system("pause");
	}
	else
	{

		cout << temp->data << "  ";
		temp = temp->next;
		print(temp);
	}
}
int main() {
restart:
	system("cls");
	cout << endl<<"开始创建栈" << endl;
	system("pause");
	node *top = new node;
	*top=createstack();
	int select;
	do {
		system("cls");
		cout << "\n\n请选择功能：\n1.元素入栈\n2.遍历元素\n3.元素出栈\n4.清空栈并重新开始\n0.退出\n请输入功能序号：";
		cin >> select;
		switch (select)
		{
		case 1:push(top);
			break;
		case 2:cout << endl;
			   print(top);
			break;
		case 3:
			top=pop(top);
			break;
		case 4:delete top;
			goto restart;
		case 0:break;
		default:cout << "输入错误" << endl;
			break;
		}
	} while (select != 0);
	return 0;
}