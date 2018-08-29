#!/bin/sh
./asm champs/Car.s
diff champs/Car.cor champs/orig/Car.cor
echo "-----------------------------------"
./asm champs/42.s
diff champs/42.cor champs/orig/42.cor
echo "-----------------------------------"
./asm champs/barriere.s
diff champs/barriere.cor champs/orig/barriere.cor
echo "-----------------------------------"
./asm champs/Gagnant.s
diff champs/Gagnant.cor champs/orig/Gagnant.cor
echo "-----------------------------------"
./asm champs/jumper.s
diff champs/jumper.cor champs/orig/jumper.cor
echo "-----------------------------------"
./asm champs/maxidef.s
diff champs/maxidef.cor champs/orig/maxidef.cor
echo "-----------------------------------"
./asm champs/mortel.s
diff champs/mortel.cor champs/orig/mortel.cor
echo "-----------------------------------"
./asm champs/Octobre_Rouge_V4.2.s
diff champs/Octobre_Rouge_V4.2.cor champs/orig/Octobre_Rouge_V4.2.cor
echo "-----------------------------------"
./asm champs/slider2.s
diff champs/slider2.cor champs/orig/slider2.cor
echo "-----------------------------------"
./asm champs/toto.s
diff champs/toto.cor champs/orig/toto.cor
echo "-----------------------------------"
./asm champs/examples/bee_gees.s
diff champs/examples/bee_gees.cor champs/examples/origin/bee_gees.cor
echo "-----------------------------------"
./asm champs/examples/bigzork.s
diff champs/examples/bigzork.cor champs/examples/origin/bigzork.cor
echo "-----------------------------------"
./asm champs/examples/fluttershy.s
diff champs/examples/fluttershy.cor champs/examples/origin/fluttershy.cor
echo "-----------------------------------"
./asm champs/examples/helltrain.s
diff champs/examples/helltrain.cor champs/examples/origin/helltrain.cor
echo "-----------------------------------"
./asm champs/examples/turtle.s
diff champs/examples/turtle.cor champs/examples/origin/turtle.cor
echo "-----------------------------------"
./asm champs/examples/zork.s
diff champs/examples/zork.cor champs/examples/origin/zork.cor
echo "-----------------------------------"
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/Backward.s
echo "---"
./asm champs/Backward.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/Death.s
echo "---"
./asm champs/Death.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/lde.s
echo "---"
./asm champs/lde.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/leeloo.s
echo "---"
./asm champs/leeloo.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/new.s
echo "---"
./asm champs/new.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/sebc.s
echo "---"
./asm champs/sebc.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/Survivor.s
echo "---"
./asm champs/Survivor.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/tdc2.s
echo "---"
./asm champs/tdc2.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/tdc3.s
echo "---"
./asm champs/tdc3.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/tdc4.s
echo "---"
./asm champs/tdc4.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
./orig_asm champs/Torpille.s
echo "---"
./asm champs/Torpille.s
echo "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"
