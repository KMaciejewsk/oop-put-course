public interface Forecast {
  float real_temperature(float temperature);
  final class Fake implements Forecast {
      @Override
      public float real_temperature(float temperature) {
          return temperature;
      }
  }
}
