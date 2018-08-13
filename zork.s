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
wadsadadasdasdaddsadasdasdadsdsadasdasdasdasdadasddadsadadsadasdasdasdsadasdasdasdasdasdasdasasdasdadad
esdadsdasdsadassadadsadasdasdasdasdasddsadasdasdasdasdsadasddadsaadadasdadadasdasdasdasdadasdasdasdasd
f
f"

l2:		sti r1, %:live, %1
		and r1, %0, r1

live:	live %1
		zjmp %:live
