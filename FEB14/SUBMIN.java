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
		LittleElephantAndSubarrays solver = new LittleElephantAndSubarrays();
		solver.solve(1, in, out);
		out.close();
	}
}
 
class LittleElephantAndSubarrays {
    public void solve(int testNumber, InputReader in, OutputWriter out) {
 
		int N  = in.readInt();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = in.readInt();
		}
		int Q = in.readInt();
		for (int i = 0; i < Q; i++) {
			int K = in.readInt();
			out.printLine(getNumSubArray(A,K, N));
		}
 
	}
 
	private int getNumSubArray(int[] a, int k, int N) {
		int cnt = 0;
		int posR = 0;
		int add = 0;
		boolean kFound = false;
		for (int i = N-1; i >= 0; i--) {
			if (a[i] > k) {
				posR++;
			}
			else if (a[i] == k) {
				kFound = true;
				posR++;
				add = posR;
			}
			else if (a[i] < k) {
				posR = 0;
				kFound = false;
			}
			if (kFound) {
				cnt += add;
			}
		}
		return cnt;
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
 
	public int readInt() {
		int c = read();
		while (isSpaceChar(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!isSpaceChar(c));
		return res * sgn;
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