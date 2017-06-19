.class public output
.super java/lang/Object
.field public static _sc Ljava/util/Scanner;
.method public static _f(I)V
.limit stack 300
.limit locals 6
return
.end method
.method public static _main()V
.limit stack 300
.limit locals 6
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "3"
invokestatic java/lang/Double/parseDouble(Ljava/lang/String;)D
ldc 5
ldc 55
imul
i2d
dadd
invokevirtual java/io/PrintStream/print(D)V
ldc 5
invokestatic output/_f(I)V
return
.end method
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 10
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V
putstatic output/_sc Ljava/util/Scanner;
invokestatic output/_main()V
return
.end method
