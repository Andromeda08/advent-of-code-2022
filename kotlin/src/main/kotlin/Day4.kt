fun main() {
    val parsedInput = Resource("input_day4.txt").readLines()
        .map { line ->
            val a = line.substringBefore(',').split('-').map{ it.toInt() }
            val b = line.substringAfter(',').split('-').map{ it.toInt() }
            (a[0]..a[1]) to (b[0]..b[1])
        }

    fun part1() {
        val result = parsedInput.count { (a, b) ->
            (a.first in b) && (a.last in b) || (b.first in a) && (b.last in a)
        }
        println("Part 1 : $result")
    }

    fun part2() {
        val result = parsedInput.count { (a, b) -> a.intersect(b).isNotEmpty() }
        println("Part 2 : $result")
    }

    part1()
    part2()
}