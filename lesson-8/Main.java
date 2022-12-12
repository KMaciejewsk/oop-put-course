public class Application {
    public static void Main(String[] args) {
        Forecast forecast = new Forecast.Fake();
        Weather weather = new Weather(forecast, 18.9f);
        Weather temperature_irl = weather.real_temperature();
        System.out.print(weather.real_temperature());
        System.out.print(temperature_irl.to_string());
        System.out.print(forecast.real_temperature(18.9f));
        assert "18.9".equals(temperature_irl.to_string());
    }
}
