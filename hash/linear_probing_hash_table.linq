<Query Kind="Program">
  <NuGetReference>NetVimClient</NuGetReference>
</Query>

void Main()
{
	InitHashTable();
	
	string Name01 = "xia";
	string Name02 = "xjapan";
	string Name03 = "xyz";
	
	SaveData(Name01, 12345);
	SaveData(Name02, 34567);
	SaveData(Name03, 67890);
	
	Console.WriteLine(GetValue(Name01));
	Console.WriteLine(GetValue(Name02));
	Console.WriteLine(GetValue(Name03));
}

// Define other methods, classes and namespaces here
public class Bucket
{
	public string key;
	public int value;
	
	public Bucket()
	{
		key = "";
		value = 0;
	}
}

static Bucket[] HashTable = new Bucket[10];

void InitHashTable()
{
	for(int i=0; i<HashTable.Length; ++i)
	{
		HashTable[i] = new Bucket();
	}
}

int HashFunction(string InKey)
{
	return (int)(InKey[0]) % 10;
}

void SaveData(string InKey, int InValue)
{
	int HashAddress = HashFunction(InKey);
	if(HashTable[HashAddress].key != "")
	{
		for(int i=HashAddress; i<HashTable.Length; ++i)
		{
			if(HashTable[i].key == "")
			{
				HashTable[i].key = InKey;
				HashTable[i].value = InValue;
				return;
			}
			else if(HashTable[i].key == InKey)
			{
				HashTable[i].value = InValue; 
			}
		}
	}
	else
	{
		HashTable[HashAddress].key = InKey;
		HashTable[HashAddress].value = InValue;
	}
}

int GetValue(string InKey)
{
	int HashAddress = HashFunction(InKey);
	if(HashTable[HashAddress].key != "")
	{
		for(int i=HashAddress; i<HashTable.Length; ++i)
		{
			if(HashTable[i].key == "")	return -1;
			else if(HashTable[i].key == InKey) return HashTable[i].value;
		}
	}
	
	return -1;
}