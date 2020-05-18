<Query Kind="Program" />

void Main()
{
	string Name01 = "Dan";
	string Name02 = "Demi";
	string Name03 = "Dony";

	Console.WriteLine(HashFunction(Name01));
	Console.WriteLine(HashFunction(Name02));
	Console.WriteLine(HashFunction(Name03));
/*
	for (int i = 0; i < 10; ++i)
	{
		HashTable[i] = new LinkedList(); 
	}
	
	Console.WriteLine(HashTable.Length);
*/	
	InitHashTable();
	
	SaveData(Name01, 1234);
	SaveData(Name02, 5678);
	SaveData(Name03, 9876);
	
	Console.WriteLine(GetValue(Name01));
	Console.WriteLine(GetValue(Name02));
	Console.WriteLine(GetValue(Name03));
	
	/*
	var list = new LinkedList();

	var newNode = new Node("Andy", 1234);
	list.PushBack(newNode);

	newNode = new Node("Trump", 65432);
	list.PushBack(newNode);

	var currentNode = list.headNode;
	do
	{
		Console.WriteLine(currentNode.key);
		Console.WriteLine(currentNode.data);
		currentNode = currentNode.nextNode;
	}while(currentNode != list.headNode);
	*/
}

// Define other methods, classes and namespaces here
public class Node
{
	public string key;
	public int data;
	public Node prevNode;
	public Node nextNode;
	
	public Node(string InKey="", int InData=0)
	{
		key = InKey;
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

	public bool IsEmpty()
	{
		if(headNode == null || elementCount == 0)
		{
			return true;
		}
		
		return false;
	}

	public int Size()
	{
		return elementCount;
	}
	
	public void PushBack(Node InElement)
	{
		if(IsEmpty())
		{
			headNode = InElement;
			tailNode = headNode;
			headNode.prevNode = tailNode;
			tailNode.nextNode = headNode;
			elementCount++;
		}
		else
		{
			Node CurrentNode = tailNode;
			CurrentNode.nextNode = InElement;
			InElement.prevNode = CurrentNode;
			tailNode = InElement;
			tailNode.nextNode = headNode;
			headNode.prevNode = tailNode;
			elementCount++;
		}
	}
	
	public bool PopBack()
	{
		if(IsEmpty())	return false;
	
		if(headNode == tailNode)
		{
			headNode = null;
			tailNode = null;
			elementCount--;
		}
		else
		{
			Node currentNode = tailNode;
			tailNode = currentNode.prevNode;
			headNode.prevNode = tailNode;
			tailNode.nextNode = headNode;
			elementCount--;
		}
		
		return true;
	}
	
	public Node GetNode(string InKey)
	{
		if(IsEmpty())	return null;
		
		Node currentNode = headNode;
		do
		{
			if(currentNode.key == InKey)	return currentNode;
			currentNode = currentNode.nextNode;
		}while(currentNode != headNode);
		
		return null;
	}
}

static LinkedList[] HashTable = new LinkedList[10];

void InitHashTable()
{
	for(int i=0; i<HashTable.Length; ++i)
	{
		HashTable[i] = new LinkedList();
	}
}

int HashFunction(string InKey)
{
	return (int)(InKey[0]) % 10;
}

void SaveData(string InKey, int InValue)
{
	int HashAddress = HashFunction(InKey);
	Node newNode = new Node(InKey, InValue);
	Console.WriteLine(HashAddress);
	HashTable[HashAddress].PushBack(newNode);
}

int GetValue(string InKey)
{
	int HashAddress = HashFunction(InKey);
	Node newNode = HashTable[HashAddress].GetNode(InKey);
	if(newNode != null) return newNode.data;
	else return -1;
}