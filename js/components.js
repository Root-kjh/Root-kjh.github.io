document.addEventListener("DOMContentLoaded", function () {
  // Header 로드
  fetch("/components/header.html")
    .then((response) => response.text())
    .then((data) => {
      document.querySelector("header").innerHTML = data;
    });

  // Footer 로드
  fetch("/components/footer.html")
    .then((response) => response.text())
    .then((data) => {
      document.querySelector("footer").innerHTML = data;
    });
});
