.class public demo
.super java/lang/Object
.field public static _sc Ljava/util/Scanner;
.method public static _main()V
.limit stack 300
.limit locals 5
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "fww\\vew\nvwev\tewv\"vwe\"vwe"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 10
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V
putstatic demo/_sc Ljava/util/Scanner;
invokestatic demo/_main()V
return
.end method
