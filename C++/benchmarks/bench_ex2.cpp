#include <benchmark/benchmark.h>
#include <string.h>

static void BM_memcpy(benchmark::State& state) {
	char* src = new char[state.range(0)];
	char* dst = new char[state.range(0)];
	memset(src, 'x', state.range(0));
	for (auto _ : state)
		memcpy(dst, src, state.range(0));
	state.SetBytesProcessed(int64_t(state.iterations()) *
			int64_t(state.range(0)));
	delete[] src;
	delete[] dst;
}

BENCHMARK(BM_memcpy)->RangeMultiplier(2)->Range(8, 8<<10);

static void BM_StringCreation(benchmark::State& state) {
	for (auto _ : state)
		std::string empty_string;
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
	std::string x = "hello";
	for (auto _ : state)
		std::string copy(x);
}
BENCHMARK(BM_StringCopy);

static void BM_DenseRange(benchmark::State& state) {
	for(auto _ : state) {
		std::vector<int> v(state.range(0), state.range(0));
		benchmark::DoNotOptimize(v.data());
		benchmark::ClobberMemory();
	}
}

BENCHMARK(BM_DenseRange)->DenseRange(0, 1024, 128);

BENCHMARK_MAIN();
