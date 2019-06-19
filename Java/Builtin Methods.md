## Reverse a String

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
}```
