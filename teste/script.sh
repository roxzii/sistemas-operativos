#!/bin/bash
APELIDO="Alves"
VARIAVEL=$stdin

if [[ $# -gt 1 ]]
then
	echo "Demasiados argumentos."
else
	echo "Bom dia, $1 $APELIDO!"
	echo "$VARIAVEL"
fi
