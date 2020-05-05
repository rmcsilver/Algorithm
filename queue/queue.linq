<Query Kind="Program" />

void Main()
{
	var queue = new Queue();

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

public class Queue
{
	public Node headNode;
	public Node tailNode;
	public int elementCount;
	
	public Queue()
	{
		headNode = null;
		tailNode = null;
		elementCount = 0;
	}
	
	public int GetSize()
	{
		return elementCount;
	}
	
	public bool IsEmpty()
	{
		return elementCount == 0;
	}
	
	public void PrintData()
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
			Count++;
			Console.WriteLine(Count + "번째 데이터 : " + currentNode.data);
			currentNode = currentNode.nextNode;
		}while(currentNode != headNode);
	}
	
	public void PushData(int InData)
	{
		Node pushNode = new Node(InData);
		
		if(headNode == null)
		{
			headNode = pushNode;
			tailNode = headNode;
		}
		else
		{
			Node currentNode = headNode;
			currentNode.prevNode = pushNode;
			pushNode.nextNode = currentNode;
			headNode = pushNode;
		}
		
		headNode.prevNode = tailNode;
		tailNode.nextNode = headNode;
		elementCount++;
	}
	
	public int PopData()
	{
		if(headNode == null)
		{
			Console.WriteLine("데이터가 없습니다.");
			return -1;
		}
		
		Node popNode = tailNode;
		int data = popNode.data;
		if(headNode == tailNode)
		{
			popNode = null;
			headNode = null;
			tailNode = null;
		}
		else
		{
			tailNode = popNode.prevNode;
			tailNode.nextNode = headNode;
			headNode.prevNode = tailNode;
			popNode = null;
		}
		
		elementCount--;
		return data;
	}
}