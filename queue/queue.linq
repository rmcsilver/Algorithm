<Query Kind="Program" />

void Main()
{
	Queue queue = new Queue();

	queue.PrintData();

	queue.PushData(10);
	queue.PrintData();
	Console.WriteLine("현재 큐의 사이즈 : " + queue.GetSize());

	for (int i = 0; i < 10; ++i)
	{
		queue.PushData(i);
	}

	queue.PrintData();
	Console.WriteLine("현재 큐의 사이즈 : " + queue.GetSize());

	queue.PopData();
	queue.PopData();

	queue.PrintData();
	Console.WriteLine("현재 큐의 사이즈 : " + queue.GetSize());
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

public class Queue
{
	public Node HeadNode;
	public Node TailNode;
	public int ElementCount;
	
	public Queue()
	{
		HeadNode = null;
		TailNode = null;
		ElementCount = 0;
	}
	
	public int GetSize()
	{
		return ElementCount;
	}
	
	public bool IsEmpty()
	{
		return ElementCount == 0;
	}
	
	public void PrintData()
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
			Count++;
			Console.WriteLine(Count + "번째 데이터 : " + CurrentNode._data);
			CurrentNode = CurrentNode._nextNode;
		}while(CurrentNode != HeadNode);
	}
	
	public void PushData(int data)
	{
		Node PushNode = new Node(data);
		
		if(HeadNode == null)
		{
			HeadNode = PushNode;
			TailNode = HeadNode;
		}
		else
		{
			Node CurrentNode = HeadNode;
			CurrentNode._prevNode = PushNode;
			PushNode._nextNode = CurrentNode;
			HeadNode = PushNode;
		}
		
		HeadNode._prevNode = TailNode;
		TailNode._nextNode = HeadNode;
		ElementCount++;
	}
	
	public int PopData()
	{
		if(HeadNode == null)
		{
			Console.WriteLine("데이터가 없습니다.");
			return -1;
		}
		
		Node PopNode = TailNode;
		int data = PopNode._data;
		if(HeadNode == TailNode)
		{
			PopNode = null;
			HeadNode = null;
			TailNode = null;
		}
		else
		{
			TailNode = PopNode._prevNode;
			TailNode._nextNode = HeadNode;
			HeadNode._prevNode = TailNode;
			PopNode = null;
		}
		
		ElementCount--;
		return data;
	}
}