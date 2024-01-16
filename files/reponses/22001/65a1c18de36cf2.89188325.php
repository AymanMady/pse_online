<?php
include_once("controller.php");
?>
<title>Inscription</title>

<div class="container-scroller">
    <div class="container-fluid page-body-wrapper full-page-wrapper">
        <div class="content-wrapper d-flex align-items-center auth">
            <div class="row flex-grow">
                <div class="col-lg-4 mx-auto">
                    <div class="auth-form-light text-left p-5">
                        <form action="" method="POST">
                            <?php
                            if ($errors > 0) {
                                foreach ($errors as $displayErrors) {
                            ?>
                                    <div id="alert"><?php echo $displayErrors; ?></div>
                            <?php
                                }
                            }
                            ?>
                            <div class="form-group">
                                <input type="text" name="fname" required placeholder="Nom" class="form-control form-control-lg">
                            </div>
                            <div class="form-group">
                                <input type="text" name="lname" required placeholder="Prénom" class="form-control form-control-lg">
                            </div>
                            <div class="form-group">
                                <input type="password" name="password" required placeholder="Mot de passe" class="form-control form-control-lg">
                            </div>
                            <div class="form-group">
                                <input type="password" name="confirmPassword" required placeholder="Confirmer le mot de passe" class="form-control form-control-lg">
                            </div>
                            <div class="mt-3">
                                <center>
                                    <input type="submit" name="signup" value="Valider" class="btn btn-block btn-gradient-primary btn-lg font-weight-medium auth-form-btn">
                                </center>
                            </div>
                            <div class="mt-4 font-weight-light">
                                <div class="text-center mt-4 font-weight-light">Vous avez déjà un compte ? <a href="authentification.php" class="text-primary">Connectez-vous</a></div>
                            </div>
                        </form>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>
