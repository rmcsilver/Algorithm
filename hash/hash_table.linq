<Query Kind="Program" />

void Main()
{
	HashTable hash = new HashTable(5);
	hash.add("Andy", "01Ta0123");
	Print(hash);

	hash.add("bred", "1004Troy");
	hash.add("Tom", "andToms666");
	hash.add("Neyo", "becauseofyou");
	hash.add("oscar", "mike");

	Print(hash);
}

// Define other methods, classes and namespaces here

struct data
{
	string key;
	string value;
	public data(string InKey=null, string InValue=null)
	{
		key = InKey;
		value = InValue;
	}
	public bool IsEmpty()
	{
		bool result = false;
		if(key == null && value == null)
		{
			result = true;
		}
		return result;
	}
	public void SetKey(string InKey){key = InKey;}
	public void SetValue(string InValue){value = InValue;}
	public string GetKey(){return key;}
	public string GetValue(){return value;}
};

class HashTable
{
	int size;
	data[] table;
	int entry_count;
	
	public HashTable(int InSize=13)
	{
		size = InSize;
		table = new data[size];
		entry_count = 0;
	}

	public int hash(string InKey)
	{
		int sum = 0;
		for (int i = 0; i < InKey.Length; ++i)
		{
			sum += InKey[i];
		}
		return sum % this.size;
	}

	public int hash_horner(string InKey)
	{
		int sum = 0;
		int primeNum = 13;
		for(int i=0; i<InKey.Length; ++i)
		{
			sum += sum * primeNum + InKey[i]; 
		}
		return sum % this.size;
	}
	
	public void add(string InKey, string InValue)
	{
		add_internal(InKey, InValue, this.table, this.size);
	}
	
	public void add_internal(string InKey, string InValue, data[] InTable, int InSize, bool resizing=false)
	{
		int index = hash(InKey);
		//Console.WriteLine("debug index : {0:D}", index);
		if(InTable[index].IsEmpty())
		{
			InTable[index].SetKey(InKey);
			InTable[index].SetValue(InValue);
		}
		else
		{
			bool result = false;
			int attempt_count = 0;
			while(result == false)
			{
				index = (hash_horner(InKey) + attempt_count) % InSize;
				if(InTable[index].IsEmpty())
				{
					InTable[index].SetKey(InKey);
					InTable[index].SetValue(InValue);
					result = true;
				}
				else attempt_count++;
			}
		}
		
		if(resizing == false)
		{
			this.entry_count++;
			if(this.entry_count > InSize * 0.7)
			{
				resize();
			}
		}
	}
	
	public bool resize()
	{
		bool result = false;
		int new_size = 0;
		new_size = this.size * 2;
		data[] new_table = new data[new_size];
		for(int i=0; i<size; ++i)
		{
			if(this.table[i].IsEmpty() == false)
			{
				add_internal(this.table[i].GetKey(), this.table[i].GetValue(), new_table, new_size, true); 
			}
		}
		size = new_size;
		table = new_table;
		
		return result;
	}
	
	public int GetSize(){return this.size;}
	public data GetData(int InIndex){return this.table[InIndex];}
}

void Print(HashTable InTable)
{
	for(int i=0; i<InTable.GetSize(); ++i)
	{
		data currentData = InTable.GetData(i);
		if(currentData.IsEmpty() == false)
		{
			Console.WriteLine("["+i.ToString()+"] -> key ="+currentData.GetKey()+", value ="+currentData.GetValue());
		}
		else
		{
			Console.WriteLine("["+i.ToString()+"] -> key = null, value = null");
		}
	}
	Console.WriteLine("\n");
}