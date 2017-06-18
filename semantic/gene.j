.class public demo
.super java/lang/Object
.field public static _sc Ljava/util/Scanner;
.field public static glo I
.method public static _g()V
.limit stack 0
.limit locals 0
ldc 1
ldc 1
iadd
return
.end method
.method public static _first()I
.limit stack 0
.limit locals 3
iload 1
i2f
ldc "1.5"
invokestatic java/lang/Float/parseFloat(Ljava/lang/String;)F
fmul
f2d
dstore 2
ldc 1
ireturn
.end method
