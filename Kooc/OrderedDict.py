
class OrderedDict:
    def __init__(self):
        self._hash = {}
        self._keys = []
        self.__contains__ = self._hash.__contains__
        self.__iter__ = self._keys.__iter__

    def __getitem__(self, key):
        return self._hash[key]

    def __setitem__(self, key, value):
        self._hash[key] = value
        if not (key in self._keys):
            self._keys.append(key)

    def __iter__(self):
      return iter(self._keys)
    
    def getHash(self):
        return self._hash

    def getList(self):
        return self._keys

    def merge(self, other):
        self._hash = dict(list(self._hash.items()) + list(other.getHash().items()))
        self._keys.extend(other.getList())
        for value in self._keys:
            if self._keys.count(value) != 1:
                i = 0
                th = False
                for k in self._keys:
                    if k == value:
                        if th == False:
                            th = True
                        else:
                            self._keys.pop(i)
                    i = i + 1
        self.__contains__ = self._hash.__contains__
        self.__iter__ = self._keys.__iter__

    def dump(self):
        for p in self._keys:
            print(self._hash[p])
