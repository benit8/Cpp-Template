#!/bin/bash
set -e

############################################################

build_dir='build'
project_bin='Project'

############################################################

has_build_dir() {
	[ -d "$build_dir" ]
}

is_built() {
	has_build_dir && [ -x "$build_dir/$project_bin" ]
}

############################################################

function build()
{
	if ! has_build_dir; then mkdir "$build_dir"; fi

	clear
	pushd "$build_dir"

	cmake .. -G "Unix Makefiles"
	cmake --build . -- -j $(nproc)

	popd
}

function run()
{
	if ! is_built; then build; fi
	"./$build_dir/$project_bin" $@
}

function run_tests()
{
	if ! is_built; then build; fi
	"./${build_dir}/tests/${project_bin}Tests" $@
}

############################################################

case "$1" in
	"")
		;&
	build)
		build
		;;
	run)
		run ${@:2}
		;;
	test)
		run_tests ${@:2}
		;;
	*)
		echo "No operation '$1' found"
		exit 1
		;;
esac