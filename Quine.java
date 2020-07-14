package other;

public class Quine {

public static void main(String[] args) {
char q = 34;
String[] l = {
"public class Quine {", 
"",
"public static void main(String[] args) {",
"char q = 34;",
"String[] l = {",
"",
"};",
"for(int i = 0; i < 5; i++)",
"System.out.println(l[i]);",
"for(int i = 0; i < l.length; i++)",
"System.out.println(l[5] + q + l[i] + q + ',');",
"for(int i = 6; i < l.length; i++)",
"System.out.println(l[i]);",
"}",
"}",
};
for(int i = 0; i < 5; i++)
System.out.println(l[i]);
for(int i = 0; i < l.length; i++)
System.out.println(l[5] + q + l[i] + q + ',');
for(int i = 6; i < l.length; i++)
System.out.println(l[i]);
}
}