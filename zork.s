.name "hello
q
w
e
r
t
"	
.comment "I'M ALIIIIVE
f
f
wadsadadasdasdaddsadasdasdad
esdadsdasdsadassadadsadasdas
f
f"
l0:
l1:
l2:     sti r16, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
