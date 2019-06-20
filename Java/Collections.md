# Java TreeSet

```Java

import java.util.*;

public class HelloWorld {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		TreeSet<Integer>st = new TreeSet<>();
		int n = sc.nextInt();
		for(int i = 0;i < n;i++) {
			int c = sc.nextInt();
			if(c > 0)st.add(c);
		}
		System.out.println(st.size());
	}
}

```
