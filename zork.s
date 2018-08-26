.name "hello"	
.comment "I'M ALIIIIVE"

l0:
l1:
l2:     sti r16, %:live, %1
		and r1, %:live, r1

live:	live %1
		zjmp %:live
