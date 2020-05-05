<Query Kind="Program" />

void Main()
{
	LinkedList list = new LinkedList();
	
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
	public int _data;
	public Node _prevNode;
	public Node _nextNode;
	
	public Node(int data=0)
	{
		_data = data;
		_prevNode = null;
		_nextNode = null;
	}
}

public class LinkedList
{
	public Node HeadNode;
	public Node TailNode;
	public int ElementCount;
	
	public LinkedList()
	{
		HeadNode = null;
		TailNode = null;
		ElementCount = 0;
	}
	
	public int GetSize()
	{
		return ElementCount;
	}
	
	public void PrintList()
	{
		if(HeadNode == null)
		{
			Console.WriteLine("출력할 데이터가 없습니다.");
			return;
		}
		
		int Count = 0;
		Node CurrentNode = HeadNode;
		do
		{
			Console.WriteLine(Count + 1 + "번째 데이터 : " + CurrentNode._data);
			CurrentNode = CurrentNode._nextNode;
			Count++;
		}while(CurrentNode != HeadNode);
	}
	
	public void InsertData(int data)
	{
		if(HeadNode == null)
		{
			Node InsertNode = new Node(data);
			HeadNode = InsertNode;
			TailNode = HeadNode;
			HeadNode._prevNode = TailNode;
			TailNode._nextNode = HeadNode;
			ElementCount++;
		}
		else
		{
			Node InsertNode = new Node(data);
			Node CurrentNode = TailNode;
			CurrentNode._nextNode = InsertNode;
			InsertNode._prevNode = CurrentNode;
			TailNode = InsertNode;		
			HeadNode._prevNode = TailNode;
			TailNode._nextNode = HeadNode;
			ElementCount++;
		}
	}
	
	public bool DeleteData(int data)
	{
		if(HeadNode == null)
		{
			Console.WriteLine("삭제할 데이터가 없습니다.");
			return false;
		}
		
		Node CurrentNode = HeadNode;
		if(CurrentNode == TailNode)
		{
			CurrentNode = null;
			HeadNode = null;
			TailNode = null;
			ElementCount--;
			return true;
		}
		
		while(CurrentNode != null)
		{
			if(CurrentNode._data == data)
			{
				Node DeleteNode = CurrentNode;
				if(CurrentNode != TailNode)
				{
					DeleteNode._prevNode._nextNode = DeleteNode._nextNode;
					DeleteNode._nextNode._prevNode = DeleteNode._prevNode;
				}
				else
				{
					TailNode = DeleteNode._prevNode;
					HeadNode._prevNode = TailNode;
					TailNode._nextNode = HeadNode;
				}
				
				DeleteNode = null;
				
				return true;
			}
			CurrentNode = CurrentNode._nextNode;
		}
		
		Console.WriteLine("데이터를 찾을 수 없습니다. 삭제실패.");
		return false;
	}
}
