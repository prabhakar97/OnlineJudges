import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    String source = s.nextLine();
    int numQueries = Integer.parseInt(s.nextLine());
    while (numQueries-- > 0) {
      String query = s.nextLine();
      System.out.println(checkSubsequence(source, query));
    }
  }

  private static String checkSubsequence(String source, String query) {
    int sourceIndex = 0;
    int queryIndex = 0;
    int firstMatch = -1;
    int lastMatch = 0;
    while (queryIndex < query.length() && sourceIndex < source.length()) {
      if (query.charAt(queryIndex) == source.charAt(sourceIndex)) {
        if (firstMatch == -1) {
          firstMatch = sourceIndex;
        }
        if (queryIndex == query.length() - 1) {
          lastMatch = sourceIndex;
        }
        queryIndex++;
        sourceIndex++;
      } else {
        sourceIndex++;
      }
    }
    if (queryIndex == query.length()) {
      return "Matched " + firstMatch + " " + lastMatch;
    } else {
      return "Not matched";
    }
  }
}
