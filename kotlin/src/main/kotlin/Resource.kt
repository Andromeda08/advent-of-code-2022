import java.io.File
import java.net.URI

class Resource(private val name: String) {
    fun uri(): URI = Resource::class.java.classLoader.getResource(name)!!.toURI()
    fun readLines(): List<String> = File(uri()).readLines()
}