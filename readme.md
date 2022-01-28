
This example shows how to use the gb.sound.play( uint16_t* pattern , bool loop = false ) function to play a pattern.

The patterns make it easy to play a melody with a nice sound of 8-bit machines.
The Gamebuino META's audio mixer has 4 channels, which allows you to play up to 4 sounds at the same time.
Be careful not make marmelade with tracks and channels !
The tracks are music (or sound effects)
Channels are playback devices capabilities, mixed on the speaker (or headphone output) of the console.

The pattens are 16 bits words :
high byte is used for the duration of the note in number of frames, from 0 to 255.
low byte is used to code on the 6 most significant bits of the note itself, from 0 to 63. The last 2 bits must have the value 0.
|Pitch|Anglosaxon Note|European Note|
|-|-|-|
|0|A#|LA#|
|1|B|SI|
|2|C|DO|
|3|C#|DO#|
|4|D|RE|
|5|D#|RE#|
|6|E|MI|
|7|F|FA|
|8|F#|FA#|
|9|G|SOL|
|10|G#|SOL#|
|11|A|LA|
|12|A# octave +1|LA#|
|13|B octave +1|SI|
|14|C octave +1|DO|
|...|...|...|
|63|silence|silence|

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

|Pitch|Note|
|-|-|
|0|LA#|
|1|SI|
|2|DO|
|3|DO#|
|4|RE|
|5|RE#|
|6|MI|
|7|FA|
|8|FA#|
|9|SOL|
|10|SOL#|
|11|LA|
|12|LA# octave +1|
|13|SI  octave +1|
|14|DO  octave +1|
|...|...|
|63|silence|

Pour encoder un LA du premier octave d'une durée de 10 images, le pattern doit avoir la valeur 10<<8 + 11<<2
