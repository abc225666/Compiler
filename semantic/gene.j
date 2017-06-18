.class public demo
.super java/lang/Object
.field public static _sc Ljava/util/Scanner;
.method public static _main()V
.limit stack 300
.limit locals 10
ldc 1
ldc 1
istore 0
ldc 0
istore 1
LOOP_START_0:
iload 0
ldc 1000
if_icmple TRUE_0
bipush 0
goto END_0
TRUE_0:
bipush 1
END_0:
ifeq LOOP_END_0
iload 1
iload 0
iadd
istore 1
iload 0
ldc 1
iadd
istore 0
NEXT_0:
goto LOOP_START_0
LOOP_END_0:
ldc 0
istore 2
LOOP_START_1:
iload 2
ldc 3
if_icmplt TRUE_1
bipush 0
goto END_1
TRUE_1:
bipush 1
END_1:
ifeq LOOP_END_1
ldc 0
istore 3
LOOP_START_2:
iload 3
ldc 3
if_icmplt TRUE_2
bipush 0
goto END_2
TRUE_2:
bipush 1
END_2:
ifeq LOOP_END_2
ldc 0
istore 4
LOOP_START_3:
iload 4
ldc 3
if_icmplt TRUE_3
bipush 0
goto END_3
TRUE_3:
bipush 1
END_3:
ifeq LOOP_END_3
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "w = "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 4
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
NEXT_3:
iload 4
ldc 1
iadd
istore 4
goto LOOP_START_3
LOOP_END_3:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "k = "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 3
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
NEXT_2:
iload 3
ldc 1
iadd
istore 3
goto LOOP_START_2
LOOP_END_2:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "j = "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 2
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
NEXT_1:
iload 2
ldc 1
iadd
istore 2
goto LOOP_START_1
LOOP_END_1:
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 0
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc " "
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
invokevirtual java/io/PrintStream/print(I)V
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
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
