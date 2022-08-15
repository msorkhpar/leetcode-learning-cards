from typing import Dict


class RansomNote:

    def can_construct(self, ransom_note: str, magazine: str) -> bool:
        magazine_map: Dict[str, int] = dict()

        for character in magazine:
            frequency = magazine_map.get(character, 0)
            magazine_map[character] = frequency + 1

        for character in ransom_note:
            frequency = magazine_map.get(character, 0)
            magazine_map[character] = frequency - 1
            if magazine_map[character] < 0:
                return False

        return True
