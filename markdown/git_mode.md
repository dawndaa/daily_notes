```
type blob = array<byte>
type tree = max<string, tree | blob>
type commit = struct {

}
type object = blob | tree | commit
objects = map<string, object>
def stroe(object):
	id = sha1(object);
	objects[id] = object;
def load(id):
	return object[id];
references = max<string, string>
def update_reference()
```

