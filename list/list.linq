<Query Kind="Program" />

void Main()
{
	var list = new LinkedList();
	
	Console.WriteLine(list.GetSize());
	list.PrintList();
	
	list.InsertData(10);
	list.PrintList();
	
	list.DeleteData(10);
	list.PrintList();
	
	for(int i=0; i<10; ++i)
	{
		list.InsertData(i);
	}
	
	list.PrintList();
	Console.WriteLine("리스트 사이즈 : " + list.GetSize());
	
	list.DeleteData(5);
	list.PrintList();
}

// Define other methods, classes and namespaces here

public class Node
{
	public int data;
	public Node prevNode;
	public Node nextNode;
	
	public Node(int InData=0)
	{
		data = InData;
		prevNode = null;
		nextNode = null;
	}
}

public class LinkedList
{
	public Node headNode;
	public Node tailNode;
	public int elementCount;
	
	public LinkedList()
	{
		headNode = null;
		tailNode = null;
		elementCount = 0;
	}
	
	public int GetSize()
	{
		return elementCount;
	}
	
	public void PrintList()
	{
		if(headNode == null)
		{
			Console.WriteLine("출력할 데이터가 없습니다.");
			return;
		}
		
		int Count = 0;
		Node currentNode = headNode;
		do
		{
			Console.WriteLine(Count + 1 + "번째 데이터 : " + currentNode.data);
			currentNode = currentNode.nextNode;
			Count++;
		}while(currentNode != headNode);
	}
	
	public void InsertData(int InData)
	{
		if(headNode == null)
		{
			Node insertNode = new Node(InData);
			headNode = insertNode;
			tailNode = headNode;
			headNode.prevNode = tailNode;
			tailNode.nextNode = headNode;
			elementCount++;
		}
		else
		{
			Node insertNode = new Node(InData);
			Node currentNode = tailNode;
			currentNode.nextNode = insertNode;
			insertNode.prevNode = currentNode;
			tailNode = insertNode;		
			headNode.prevNode = tailNode;
			tailNode.nextNode = headNode;
			elementCount++;
		}
	}
	
	public bool DeleteData(int data)
	{
		if(headNode == null)
		{
			Console.WriteLine("삭제할 데이터가 없습니다.");
			return false;
		}
		
		Node deleteNode = headNode;
		if(deleteNode == tailNode && deleteNode.data == data)
		{
			deleteNode = null;
			headNode = null;
			tailNode = null;
			elementCount--;
			return true;
		}
		
		while(deleteNode != null)
		{
			if(deleteNode.data == data)
			{
				if(deleteNode != tailNode)
				{
					deleteNode.prevNode.nextNode = deleteNode.nextNode;
					deleteNode.nextNode.prevNode = deleteNode.prevNode;
				}
				else
				{
					tailNode = deleteNode.prevNode;
					headNode.prevNode = tailNode;
					tailNode.nextNode = headNode;
				}
				
				deleteNode = null;
				
				return true;
			}
			deleteNode = deleteNode.nextNode;
		}
		
		Console.WriteLine("데이터를 찾을 수 없습니다. 삭제실패.");
		return false;
	}
}