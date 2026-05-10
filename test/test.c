int main() {
	VerbumContext vc= {
		.io = {
			.source = source,
			.at_end = at_end,
			.close = close2,
			.copy_from = copy_from,
			.get = get,
			.tell = tell,
			.unget = unget,
			.open = open2,
		},
		.memory = {
			.copy = copy,
			.delete = delete,
			.new = new,
			.resize = resize,
		},
	};

	return 0;
}
