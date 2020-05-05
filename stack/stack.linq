<Query Kind="Program" />

void Main()
{
	Stack stack = new Stack();
	Console.WriteLine("현재 스택의 사이즈 : " + stack.GetSize());
	stack.PrintData();

	stack.PushData(10);
	stack.PrintData();
	Console.WriteLine("현재 스택의 사이즈 : " + stack.GetSize());

	for(var i=0; i<10; ++i)
	{
		stack.PushData(i);
	}
	stack.PrintData();
	Console.WriteLine("현재 스택의 사이즈 : " + stack.GetSize());

	Console.WriteLine(stack.PopData() + " : 데이터 팝업");
	Console.WriteLine(stack.PopData() + " : 데이터 팝업");
	stack.PrintData();
	Console.WriteLine("현재 스택의 사이즈 : " + stack.GetSize());


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

public class Stack
{
	public Node headNode;
	public Node tailNode;
	public int elementCount;
	
	public Stack()
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
		
		int count = 0;
		Node currentNode = headNode;
		do
		{
			count++;
			Console.WriteLine(count + "번째 데이터 : " + currentNode.data);
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
			headNode.prevNode = tailNode;
			tailNode.nextNode = headNode;
		}
		else
		{
			Node currentNode = tailNode;
			currentNode.nextNode = pushNode;
			pushNode.prevNode = currentNode;
			tailNode = pushNode;
			tailNode.nextNode = headNode;
			headNode.prevNode = tailNode;
		}
		
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