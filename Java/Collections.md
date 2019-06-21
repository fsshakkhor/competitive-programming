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
# Java TreeMap

```Java

import java.util.*;


public class HelloWorld {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		TreeMap<Integer,Integer> mp = new TreeMap<>();
		for(int i = 0;i < n;i++) {
			int v = sc.nextInt();
			if(mp.containsKey(v)) {
				int c = mp.get(v);
				mp.put(v,c + 1);
			}else {
				mp.put(v, 1);
			}
		}
		if(mp.size() == 2) {
			int values[] = new int[2];
			int key[] = new int[2];
			int index = 0;
			for (Map.Entry<Integer, Integer> mapEntry  : mp.entrySet()) {
			    values[index] = mapEntry.getValue();
			    key[index] = mapEntry.getKey();
			    index++;
			}
			if(values[0] == values[1]) {
				System.out.println("YES");
				System.out.println(key[0] + " " + key[1]);
			}else {
				System.out.println("NO");
			}
		}else {
			System.out.println("NO");
		}
	}
}
```

# Java Priority Queue

```Java

import java.util.*;


public class HelloWorld {
	
    static Comparator<Long> PQComparator = new Comparator<Long>() {
        @Override
        public int compare(Long s1, Long s2) {
            return (int)(s1 - s2);
        }
    };
    
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		Long ara[] = new Long[n];
	    PriorityQueue<Long> Q = new PriorityQueue<>(PQComparator);
		for(int i = 0;i < n;i++) {
			ara[i] = sc.nextLong();
			Q.add(ara[i]);
		}
		int ans = 0;
		while(Q.peek() < k) {
			if(Q.size() == 1)break;
			Long a = Q.peek();
			Q.remove();
			Long b = Q.peek();
			Q.remove();
			Q.add(a + 2 * b);
			ans++;
		}
		if(Q.peek() < k) {
			ans = -1;
		}
		System.out.println(ans);
	}
}
```
