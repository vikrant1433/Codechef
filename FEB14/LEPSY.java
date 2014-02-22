import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.Writer;
import java.io.InputStream;
 
/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Vikrant Singh
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		OutputWriter out = new OutputWriter(outputStream);
		LongestCommonPattern solver = new LongestCommonPattern();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}
 
class LongestCommonPattern {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
		String A = in.readString();
		String B = in.readString();
		int arrA[][] = new int[3][26];
		for (int i = 0; i < A.length(); i++) {
			char c = A.charAt(i);
			if (Character.isDigit(c)) {
				arrA[2][c-'0']++;
			}
			else if (Character.isUpperCase(c)) {
				arrA[1][c - 'A']++;
			} else {
				arrA[0][c-'a']++;
			}
		}
		int cnt=0;
		for (int i = 0; i < B.length(); i++) {
			char c = B.charAt(i);
			if (Character.isDigit(c) && arrA[2][c-'0'] > 0) {
				cnt++;
				arrA[2][c-'0']--;
			}
			else if (Character.isUpperCase(c) && arrA[1][c - 'A'] > 0) {
				cnt++;
				arrA[1][c - 'A']--;
			} else if (Character.isLowerCase(c) && arrA[0][c-'a'] > 0){
				cnt++;
				arrA[0][c-'a']--;
			}
		}
		out.printLine(cnt);
 
	}
}
 
class InputReader {
 
	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
 
	public InputReader(InputStream stream) {
		this.stream = stream;
	}
 
	public static boolean isSpaceChar(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}
 
	public int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			}
			catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}
 
	public String readString() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		StringBuffer res = new StringBuffer();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!isSpaceChar(c));
		return res.toString();
	}
 
	public String next() {
		return readString();
	}
 
}
 
class OutputWriter {
	private final PrintWriter writer;
 
	public OutputWriter(OutputStream outputStream) {
		writer = new PrintWriter(outputStream);
	}
 
	public OutputWriter(Writer writer) {
		this.writer = new PrintWriter(writer);
	}
 
	public void print(Object... objects) {
		for (int i = 0; i < objects.length; i++) {
			if (i != 0)
				writer.print(' ');
			writer.print(objects[i]);
		}
	}
 
	public void printLine(Object... objects) {
		print(objects);
		writer.println();
	}
 
	public void close() {
		writer.close();
	}
 
}