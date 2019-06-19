## Reverse a String

class Reverse
{
	// Function to reverse a string in Java using StringBuilder
	public static String reverse(String str)
	{
		return new StringBuilder(str).reverse().toString();
	}

	public static void main(String[] args)
	{
		String str = "Techie Delight";

		// Note that string is immutable in Java
		str = reverse(str);

		System.out.println("Reverse of the given string is : " + str);
	}
}
