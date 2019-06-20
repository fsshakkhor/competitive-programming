### Reverse String

```Java
class Reverse
{
	public static String reverse(String str)
	{
		return new StringBuilder(str).reverse().toString();
	}

	public static void main(String[] args)
	{
		String str = "Techie Delight";

		str = reverse(str);

		System.out.println("Reverse of the given string is : " + str);
	}
}
```
### Sort Array Built In Methods
* **Arrays.Sort()** : mainly works for primitive data types

```Java
public class HelloWorld {
	public static void main(String[] args){
		 int[] arr = {13, 7, 6, 45, 21, 9, 101, 102};
		 Arrays.sort(arr);
		 for(int i = 0;i < arr.length ;i++) {
			 System.out.print(arr[i] + " ");
		 }
	}
}
```
* **Collections.Sort()** : works for Collections such as Arraylist, Vector etc.
```Java
public class HelloWorld {
	public static void main(String[] args){
		ArrayList<String> al = new ArrayList<String>(); 
		al.add("Welcome"); 
		al.add("Friends"); 

		Collections.sort(al);
		for(int i = 0;i < al.size();i++) {
			System.out.print(al.get(i) + " ");
		}

	}
}

```

* **Arrays.sort(Integer)** is more faster than **Arrays.sort(int)** in the worst case. The first one uses Merge Sort and the later on uses Quick Sort. 

### Sort Array Using Comparator

```Java
import java.util.*;
class Student 
{ 
    int rollno; 
    String name, address; 
  
    public Student(int rollno, String name, 
                             String address) 
    { 
        this.rollno = rollno; 
        this.name = name; 
        this.address = address; 
    } 
  

    public String toString() 
    { 
        return this.rollno + " " + this.name + 
                           " " + this.address; 
    } 
} 
  
class Sortbyroll implements Comparator<Student> 
{ 
    public int compare(Student a, Student b) 
    { 
        return a.rollno - b.rollno; 
    } 
} 

public class HelloWorld {
	public static void main(String[] args){
        ArrayList<Student> ar = new ArrayList<Student>(); 
        ar.add(new Student(111, "bbbb", "london")); 
        ar.add(new Student(131, "aaaa", "nyc")); 
        ar.add(new Student(121, "cccc", "jaipur")); 
  
        System.out.println("Unsorted"); 
        for (int i=0; i<ar.size(); i++) 
            System.out.println(ar.get(i)); 
  
        Collections.sort(ar, new Sortbyroll()); 
  
        System.out.println("\nSorted by rollno"); 
        for (int i=0; i<ar.size(); i++) 
            System.out.println(ar.get(i)); 
	}
}
```
