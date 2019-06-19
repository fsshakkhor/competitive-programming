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
### Sort Array
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
