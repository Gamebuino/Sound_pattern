
This example shows how to use the gb.sound.play( uint16_t* pattern , bool loop = false ) function to play a pattern.

The patterns make it easy to play a melody with a nice sound of 8-bit machines.
The Gamebuino META's audio mixer has 4 channels, which allows you to play up to 4 sounds at the same time.
Be careful not make marmelade with tracks and channels !
The tracks are music (or sound effects)
Channels are playback devices capabilities, mixed on the speaker (or headphone output) of the console.

The pattens are 16 bits words :
high byte is used for the duration of the note in number of frames, from 0 to 255.
low byte is used to code on the 6 most significant bits of the note itself, from 0 to 63. The last 2 bits must have the value 0.
|Pitch|Note|
|-|-|
|0|A#|
|1|B|
|2|C|
|3|C#|
|4|D|
|5|D#|
|6|E|
|7|F|
|8|F#|
|9|G|
|10|G#|
|11|A|
|12|A# of octave +1|
|13|B of the octave +1|
|14|C of the octave +1|
|...|...|
|63|silence|

To encode an A of the first octave with a duration of 10 frames, the pattern must have the value 10<<8 + 11<<2.

-------------------------------------------------------------------
Cette exemple montre comment utiliser la fonction gb.sound.play( uint16_t* pattern , bool loop = false ) pour lire un pattern.

Les patterns permettent de jouer facilement une mélodie avec une jolie sonorité de machines 8 bits.
Le mélangeur audio de la Gamebuino META possède 4 canaux, qui permettenr de jouer jusqu'a 4 sons en même temps.
Attention ne pas mélanger pistes et canaux.
Les pistes sont des musiques (ou bruitages)
Les canaux audio sont des périphériques de lecture, mélangés sur le haut-parleur (ou la sortie casque) de la concole.

Les pattens sont des mots de 8 bits composés de la durée de la note (poids fort) en nombre d'images, et d'un indice de hauteur (vois ci-dessous).

La hauteur est codée sur les 6 bits de poids fort de l'octet de poids faible : les 2 derniers bits doivent avoir la valeur 0.

La hauteur 0 correspond au LA#.
La hauteur 1 correspond au SI.
La hauteur 2 correspond au DO.
La hauteur 3 correspond au DO#.
La hauteur 4 correspond au RE.
La hauteur 5 correspond au RE#.
La hauteur 6 correspond au MI.
La hauteur 7 correspond au FA.
La hauteur 8 correspond au FA#.
La hauteur 9 correspond au SOL.
La hauteur 10 correspond au SOL#
La hauteur 11 correspond au LA.
La hauteur 12 correspond au LA# de l'octave +1.
La hauteur 13 correspond au SI  de l'octave +1.
La hauteur 14 correspond au DO  de l'octave +1.
...
La hauteur 63 correspond a un silence.

Pour encoder un LA du premier octave d'une durée de 10 images, le pattern doit avoir la valeur 10<<8 + 11<<2
