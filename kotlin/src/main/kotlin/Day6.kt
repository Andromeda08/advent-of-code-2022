fun main() {
    val input = Resource("input_day6.txt").readLines()[0]

    fun findMarker(s: String, n: Int) = s.windowed(n).indexOfFirst { it.toSet().size == it.length } + n

    println("Part 1 : ${ findMarker(input, 4) }")
    println("Part 2 : ${ findMarker(input, 14) }")
}