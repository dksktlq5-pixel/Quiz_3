#include <iostream>
#include <string>
class Item                                      // 선언
{
public:
	Item()                                      // 생성자 선언
	{
		itemName = "";
		itemPrice = 0;
	}                                          // 생성자 정의
	Item(std::string name, int price)
	{
		itemName = name;
		itemPrice = price;
	}
	~Item()                                    // 소멸자 선언
	{
	}                                          // 소멸자 정의
	std::string GetItemName()
	{
		return itemName;
	}
	int GetItemPrice()
	{
		return itemPrice;
	}
private:
	std::string itemName;
	int itemPrice;                             // Item 클래스의 정수형 멤버변수 itemPrice을 선언
};                                             // 정의
template<typename T>
class Inventory
{
public:
	Inventory(int capacity = 10)
	{
		pItems = new Item[capacity];
		this->capacity = capacity;
		size = 0;
	}
	~Inventory()
	{
		delete[] pItems;
	}
	void AddItem(Item item)
	{
		if (size >= capacity)                   // 예외처리
			return;
		pItems[size++] = item;
	}
	void RemoveLastItem()
	{
		size = size - 1;
	}
	void PrintAllItems()
	{
		for (int i = 0; i < size; ++i)
		{
			std::cout << "Name : " << pItems[i].GetItemName() << ", Price : " << pItems[i].GetItemPrice() << std::endl;
		}
	}
private:
	T* pItems;
	int capacity;
	int size;
};
// 프로그램 실행시 호출되는 함수
// Item item; 이랑 Item* item = new Item(); 같은 걸로, 정의해야 사용 가능
int main()
{
	Item item("Hello Item", 1000);                               // 정의해야 사용 가능
	Inventory<Item> inventory;
	inventory.AddItem(item);
	inventory.AddItem(Item("Hello Item2", 1100));
	for (int i = 0; i < 10; ++i)
	{
		inventory.AddItem(Item("Hello Item" + std::to_string(i), 100));
	}
	inventory.RemoveLastItem();
	inventory.PrintAllItems();
	Item* itemPtr = new Item();              // 포인터: 껍데기 & Item* 형식을 가진 item을 생성
	delete itemPtr;
	return 0;                                // 프로그램 종료시 운영체제에 넘겨주는 값
}
